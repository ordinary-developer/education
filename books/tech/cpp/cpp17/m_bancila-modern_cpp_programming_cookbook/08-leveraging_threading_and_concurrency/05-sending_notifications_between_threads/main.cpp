#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream>
namespace example_01 { // < thread synchronizing with notifications on condition variables
    
std::condition_variable cv{};
std::mutex cv_mutex{};
std::mutex io_mutex{};
int data{0};
    
void run() {
    std::thread p([&](){
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(2s);
        }
        {
            std::unique_lock lock{ cv_mutex };
            data = 42;
            cv.notify_one();
        }
        
        {
            std::lock_guard lock{ io_mutex };
            std::cout << "produced " << data << std::endl;
        }
    });
    
    std::thread c([&](){
        {
            std::unique_lock lock{ cv_mutex };
            cv.wait(lock);
        }
        
        {
            std::lock_guard lock{ io_mutex };
            std::cout << "consumed " << data << std::endl;
        }
    });
    
    p.join(); c.join();
}    
    
} // example_01


#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>
#include <queue>
#include <array>
#include <vector>
#include <iostream>
namespace example_02 { // < thread synchronizing with notifications on condition variables : more elaborate example
    
using namespace std::chrono_literals;
    
std::mutex g_lockPrint;
std::mutex g_lockQueue;
std::condition_variable g_queueCheck;
std::queue<int> g_buffer;
bool g_done;
    
void producer(
    int const id,
    std::mt19937& generator,
    std::uniform_int_distribution<int>& dsleep,
    std::uniform_int_distribution<int>& dcode)
{
    for (int i{0}; i < 5; ++i) {
        // simulate work
        std::this_thread::sleep_for(std::chrono::seconds{ dsleep(generator) });
        
        // generate data
        int const value = id * 100  + dcode(generator);
        
        // print an operation status
        {
            std::unique_lock<std::mutex> locker{ g_lockPrint };
            std::cout << "[produced]: " << value << std::endl;
        }
        
        // notify consumers
        {
            std::unique_lock<std::mutex> locker{ g_lockQueue };
            g_buffer.push(value);
            g_queueCheck.notify_one();
        }
    }
}
    
void consumer() {
    while (not g_done) {
        std::unique_lock<std::mutex> locker{ g_lockQueue };
        
        g_queueCheck.wait_for(
            locker,
            std::chrono::seconds{1},
            [&]() { return not g_buffer.empty(); });
        
        while (not g_done and not g_buffer.empty()) {
            std::unique_lock<std::mutex> locker{ g_lockPrint };
            std::cout 
                << "[consumed]: " << g_buffer.front()
                << std::endl;
            g_buffer.pop();
        }
    }
}
    
    
void run() {
    auto seed_data = std::array<int, std::mt19937::state_size>{};
    std::random_device rd{};
    
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    auto generator = std::mt19937{ seq };
    auto dsleep = std::uniform_int_distribution<>{ 1, 5 };
    auto dcode = std::uniform_int_distribution<>{ 1, 99 };
    
    std::cout << "start producing and consuming ..." << std::endl;
    
    std::thread consumerThread{ consumer };
    
    std::vector<std::thread> threads{};
    for (int i{0}; i < 5; ++i) {
        threads.emplace_back(
            producer,
            i + 1,
            std::ref(generator),
            std::ref(dsleep),
            std::ref(dcode));
    }
    
    for (auto& t : threads)
        t.join();
    
    g_done = true;
    consumerThread.join();
    
    std::cout << "done producing and consuming" << std::endl;
}    
    
}
    
#include <functional>
#include <string>
#include <iostream>
int main() {
    using FuncDelegate = std::function<void(void)>;
    
    FuncDelegate const funcs[] = {
        example_01::run, example_02::run
    };
    
    unsigned int i{1};
    for (auto const& func : funcs) {
        std::string const exampleName = "example_" + std::to_string(i++);
        std::cout << exampleName << " =>\n";
        func();
        std::cout << "[ok] - " << exampleName << std::endl << std::endl;
    }
    return 0;
}

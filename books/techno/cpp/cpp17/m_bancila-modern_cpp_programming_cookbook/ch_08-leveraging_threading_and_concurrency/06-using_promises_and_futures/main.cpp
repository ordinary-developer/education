#include <thread>
#include <future>
#include <mutex>
#include <chrono>
#include <functional>
#include <iostream>
namespace example_01 { // <- get a value from a thread
    
std::mutex g_ioMutex{};
    
void produce_value(std::promise<int>& p) {
    // simulate a long running operation
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2s);
    }
    
    p.set_value(42);
}
    
void consume_value(std::future<int>& f) {
    auto const value = f.get();
    
    std::lock_guard<std::mutex> lock{ g_ioMutex };
    std::cout << value << std::endl;
}
    
void run() {
    std::promise<int> p{};
    std::thread t1{ produce_value, std::ref(p) };
    
    std::future<int> f = p.get_future();
    std::thread t2{ consume_value, std::ref(f) };
    
    t1.join();
    t2.join();
}    
} // example_01


#include <thread>
#include <future>
#include <mutex>
#include <chrono>
#include <functional>
#include <exception>
#include <iostream>
namespace example_02 { // <- get an exception from a thread
    
std::mutex g_ioMutex{};    
    
void produce_value(std::promise<int>& p) {
    // simulate long running operation
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2s);        
    }
    
    try {
        throw std::runtime_error{ "an error has occurred" };
    }
    catch (...) {
        p.set_exception(std::current_exception());
    }
}
    
void consume_value(std::future<int>& f) {
    std::lock_guard<std::mutex> lock{ g_ioMutex };
    try {
        std::cout << f.get() << std::endl;
    }
    catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}
    
void run() {
    std::promise<int> p{};
    std::thread t1{ produce_value, std::ref(p) };
    
    std::future<int> f = p.get_future();
    std::thread t2{ consume_value, std::ref(f) };
    
    t1.join();
    t2.join();
}
    
} // example_02


#include <functional>
#include <string>
#include <iostream>
int main() {
    using FuncDelegate = std::function<void(void)>;
    
    FuncDelegate const funcs[] {
        example_01::run, example_02::run
    };
    
    unsigned int i{1};
    for (auto const& func : funcs) {
        std::string const exampleName = "example_" + std::to_string(i++);
        std::cout << exampleName << " =>\n";
        func();
        std::cout << "[ok] - " << exampleName << "\n\n";
    }
    
    return 0;
}

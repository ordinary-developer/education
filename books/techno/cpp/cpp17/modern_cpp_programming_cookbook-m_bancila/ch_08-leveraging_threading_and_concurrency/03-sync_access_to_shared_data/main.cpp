#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <vector>
namespace example_01 {
    
std::mutex g_mutex{};

void thread_func() {
    using namespace std::chrono_literals;
    
    {
        std::lock_guard<std::mutex> lock{ g_mutex };
        std::cout << "running thread "
            << std::this_thread::get_id() << std::endl;
    }
    
    std::this_thread::yield();
    std::this_thread::sleep_for(2s);
    
    {
        std::lock_guard<std::mutex> lock{ g_mutex };
        std::cout << "done in thread "
            << std::this_thread::get_id() << std::endl;
    }
}
    
void run() {
    std::vector<std::thread> threads{};
    for (int i{0}; i < 5; ++i)
        threads.emplace_back(thread_func);
    
    for (auto& t : threads)
        t.join();
}
} // example_01

#include <mutex>
#include <thread>
#include <vector>
#include <functional>
namespace example_02 {
    
template <typename T>
struct container {
    std::mutex mutex;
    std::vector<T> data;
};
    
template <typename T>
void move_between(container<T>& c1, container<T>& c2, T const value) {
    std::lock(c1.mutex, c2.mutex);
    
    std::lock_guard<std::mutex> l1{ c1.mutex, std::adopt_lock };
    std::lock_guard<std::mutex> l2{ c2.mutex, std::adopt_lock };
    
    c1.data.erase(
        std::remove(c1.data.begin(), c1.data.end(), value),
        c1.data.end());
    c2.data.push_back(value);
}    
    
void run() {
    container<int> c1{};
    c1.data.push_back(1);
    c1.data.push_back(2);
    c1.data.push_back(3);
    
    container<int> c2{};
    c2.data.push_back(4);
    c2.data.push_back(5);
    c2.data.push_back(6);
    
    std::thread t1{ move_between<int>, std::ref(c1), std::ref(c2), 3 };
    std::thread t2{ move_between<int>, std::ref(c2), std::ref(c1), 6 };
    t1.join(); t2.join();
} 
} // example_02


#include <mutex>
#include <thread>
#include <vector>
#include <functional>
namespace example_03 {
    
template <typename T>
struct container {
    std::mutex mutex;
    std::vector<T> data;
};
    
template <typename T>
void move_between(container<T>& c1, container<T>& c2, T const value) {
    std::scoped_lock lock{c1.mutex, c2.mutex };
    
    c1.data.erase(
        std::remove(c1.data.begin(), c1.data.end(), value),
        c1.data.end());
    c2.data.push_back(value);
}    
    
void run() {
    container<int> c1{};
    c1.data.push_back(1);
    c1.data.push_back(2);
    c1.data.push_back(3);
    
    container<int> c2{};
    c2.data.push_back(4);
    c2.data.push_back(5);
    c2.data.push_back(6);
    
    std::thread t1{ move_between<int>, std::ref(c1), std::ref(c2), 3 };
    std::thread t2{ move_between<int>, std::ref(c2), std::ref(c1), 6 };
    t1.join(); t2.join();
}
    
} // example_03



#include <functional>
#include <array>
#include <cstddef>
#include <string>
int main() {
    using FuncDelegate = std::function<void(void)>;
    std::size_t const N{ 3 };
    std::array<FuncDelegate, N> funcs { {
        example_01::run, example_02::run, example_03::run }};
    
    std::size_t i{ 1 };
    for (auto const func : funcs) {
        func();
        std::cout << "[ok] - example " + std::to_string(i++) << std::endl << std::endl;
    }
        
    return 0;
}

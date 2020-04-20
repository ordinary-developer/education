#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <iostream>
namespace example_01 { // <- synchronize access to a single shared resource
    
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
    for (unsigned int i{0}; i < 5; ++i)
        threads.emplace_back(thread_func);
    
    for (auto& t : threads)
        t.join();
}
} // example_01


#include <thread>
#include <mutex>
#include <functional>
#include <vector>
#include <iterator>
#include <iostream>
namespace example_02 { // <- synchronize access to multiple shared resources
    
template <typename T>
struct container {
    std::mutex mut;
    std::vector<T> data;
};
    
template <typename T>
void move_between(container<T>& c1, container<T>& c2, T const value) {
    std::lock(c1.mut, c2.mut);
    
    std::lock_guard<std::mutex> l1{ c1.mut, std::adopt_lock };
    std::lock_guard<std::mutex> l2{ c2.mut, std::adopt_lock };
    
    c1.data.erase(
        std::remove(c1.data.begin(), c1.data.end(), value),
        c1.data.end());
    c2.data.push_back(value);
}
    
void run() {
    container<int> c1{ .mut{}, .data{ 1, 2, 3 } };
    container<int> c2{ .mut{}, .data{ 4, 5, 6 } };
    
    std::thread t1{ move_between<int>, std::ref(c1), std::ref(c2), 3 };
    std::thread t2{ move_between<int>, std::ref(c2), std::ref(c1), 6 };
    t1.join(); t2.join();
    
    std::cout << "container 1:\n";
    std::copy(c1.data.cbegin(), c1.data.cend(), 
        std::ostream_iterator<int>{ std::cout, "\n"} );
    
    std::cout << "container 2:\n";
    std::copy(c2.data.cbegin(), c2.data.cend(), 
        std::ostream_iterator<int>{ std::cout, "\n"} );
}
    
} // example_02


#include <thread>
#include <mutex>
#include <functional>
#include <vector>
#include <iterator>
#include <iostream>
namespace example_03 { // <- synchronize access to multiple shared resources with std::scoped_lock
    
template <typename T>
struct container {
    std::mutex mut;
    std::vector<T> data;
};
    
template <typename T>
void move_between(container<T>& c1, container<T>& c2, T const value) {
    std::scoped_lock lock{ c1.mut, c2.mut };
    
    c1.data.erase(
        std::remove(c1.data.begin(), c1.data.end(), value),
        c1.data.end());
    c2.data.push_back(value);
}    
    
void run() {
    container<int> c1{ .mut{}, .data{ 1, 2, 3 } };
    container<int> c2{ .mut{}, .data{ 4, 5, 6 } };
    
    std::thread t1{ move_between<int>, std::ref(c1), std::ref(c2), 3 };
    std::thread t2{ move_between<int>, std::ref(c2), std::ref(c1), 6 };
    t1.join(); t2.join();
    
    std::cout << "container 1:\n";
    std::copy(c1.data.cbegin(), c1.data.cend(), 
        std::ostream_iterator<int>{ std::cout, "\n"} );
    
    std::cout << "container 2:\n";
    std::copy(c2.data.cbegin(), c2.data.cend(), 
        std::ostream_iterator<int>{ std::cout, "\n"} );
    
}
    
} // example_03


#include <functional>
#include <string>
#include <iostream>
int main() {
    using FuncDelegate = std::function<void(void)>;
    
    FuncDelegate const funcs[] {
        example_01::run, example_02::run, example_03::run
    };
    
    unsigned int i{1};
    for (auto const& func : funcs) {
        func();
        std::cout << "[ok] - example " + std::to_string(i++) << std::endl << std::endl; 
    }
    
    return 0;
}

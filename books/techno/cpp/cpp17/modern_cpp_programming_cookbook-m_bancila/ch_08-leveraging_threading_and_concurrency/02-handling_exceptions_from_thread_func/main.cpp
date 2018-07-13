#include <thread>
#include <mutex>
#include <exception>
#include <vector>
#include <iostream>
namespace workspace {
std::vector<std::exception_ptr> g_exceptions{};
std::mutex g_mutex{};

void func1() { throw std::runtime_error{ "exception 1" }; }
void func2() { throw std::runtime_error{ "exception 2" }; }

void thread_func1() {
    try {
        func1();
    }
    catch (...) {
        std::lock_guard<std::mutex> lock{ g_mutex };
        g_exceptions.push_back(std::current_exception());
    }
}

void thread_func2() {
    try {
        func2();
    }
    catch (...) {
        std::lock_guard<std::mutex> lock{ g_mutex };
        g_exceptions.push_back(std::current_exception());
    }
}

void run() {
    g_exceptions.clear();
    
    std::thread t1{ thread_func1 }, t2{ thread_func2 };
    t1.join();  t2.join();
    
    for (auto const& e : g_exceptions) {
        try {
            if (nullptr != e) 
                std::rethrow_exception(e);
        }
        catch (std::exception const& e) { std::cout << e.what() << std::endl; }
    }
    
}
} // workspace


int main() {
    workspace::run();
    
    return 0;
}

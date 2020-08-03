#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <cassert>
namespace example_01 { // base usage of std::atomic<T*>
    
std::vector<int> data{};
std::atomic<bool> data_ready{false};    
    
void reader_thread() {
    while (not data_ready.load())
        std::this_thread::sleep_for(std::chrono::milliseconds{1});
    
    assert(1 == data.size());
    assert(42 == *data.begin());
}
    
void writer_thread() {
    data.push_back(42);
    data_ready = true;
}
    
void run() {
    std::thread t1{ reader_thread };
    std::thread t2{ writer_thread };
    t1.join(), t2.join();
}
} // example_01


#include <iostream>
int main() {
    std::cout << "[ok] - example 01" << std::endl; example_01::run(); std::cout << std::endl;
    
    return 0;
}

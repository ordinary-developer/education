#include <atomic>
#include <thread>
#include <cassert>
namespace workspace { // ordering non-atomic operations with atomics
    
bool x{ false };
std::atomic<bool> y{};
std::atomic<int> z{};
    
void write_x_then_y() {
    x = true;
    std::atomic_thread_fence(std::memory_order_release);
    y.store(true, std::memory_order_relaxed);
}
    
void read_y_then_x() {
    while (not y.load(std::memory_order_relaxed));
    std::atomic_thread_fence(std::memory_order_acquire);
    if (x)
        ++z;
}
  
void run() {
    x = false, y = false, z = 0;
    std::thread t1{ write_x_then_y }, t2{ read_y_then_x };
    t1.join(), t2.join();
    assert(1 == z.load());
}
} // workspace


#include <iostream>
int main() {    
    std::cout << "[ok] - workspace" << std::endl; workspace::run(); std::cout << std::endl << std::endl;
   
    return 0;
}

#include <atomic>
#include <thread>
#include <cassert>
namespace workspace {

std::atomic<bool> x{}, y{};
std::atomic<int> z{};
    
void write_x() {
    x.store(true);        // std::memory_order_seq_cst
}
   
void write_y() {
    y.store(true);        // std::memory_order_seq_cst
}
    
void read_x_then_y() {
    while (not x.load()); // std::memory_order_seq_cst
    if (y.load())         // std::memory_order_seq_cst
        ++z;
}
    
void read_y_then_x() {
    while (not y.load()); // std::memory_order_seq_cst
    if (x.load())         // std::memory_order_seq_cst
        ++z;
}
    
void run() {
    x = false, y = false, z = 0;
    
    std::thread t1{ write_x }, t2{ write_y }, 
        t3{ read_x_then_y }, t4{ read_y_then_x };
    t1.join(), t2.join(), t3.join(), t4.join();
    
    assert(1 == z.load() or 2 == z.load());
}
} // workspace


int main() {
    workspace::run();
    
    return 0;
}

#include <atomic>
#include <chrono>
#include <string>
#include <thread>
#include <cassert>
namespace example_01 { // using of std::memory_order_consume

struct X {
    int i;
    std::string s;
};
    
std::atomic<X*> atom_ptr{};
std::atomic<int> atom_var{};
    
void create_x() {
    X* x{ new X{ .i{42}, .s{"hello"} } };
    atom_var.store(99, std::memory_order_relaxed);
    atom_ptr.store(x, std::memory_order_release);
}
    
void use_x() {
    X* x{nullptr};
    while (not (x = atom_ptr.load(std::memory_order_consume)))
        std::this_thread::sleep_for(std::chrono::microseconds{1});
    assert(42 == x->i);
    assert("hello" == x->s);
    
    // 'atom_var' isn't dependent on the value loaded from p
    auto const val = atom_var.load(std::memory_order_relaxed);
    assert(99 == val or 99 != val);
}
    
void run() {
    std::thread t1{ create_x }, t2{ use_x };
    t1.join(), t2.join();
}    
} // example_01


#include <iostream>
int main() {
    std::cout << "[ok] - example_01" << std::endl; example_01::run(); std::cout << std::endl;
    
    return 0;
}

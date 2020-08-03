#include <atomic>
#include <cassert>
namespace example_01 { // base usage of std::atomic<T*>
void run() {
    struct foo{};
    
    foo some_array[5];
    std::atomic<foo*> atom_ptr{ some_array };
    foo* ptr_val{nullptr};
    
    ptr_val = atom_ptr.fetch_add(2);
    assert(some_array == ptr_val);
    assert(&some_array[2] == atom_ptr.load());
    
    ptr_val = (atom_ptr -= 1);
    assert(&some_array[1] == ptr_val);
    assert(&some_array[1] == atom_ptr.load());
    
    ptr_val = atom_ptr.fetch_add(3, std::memory_order_release);
    assert(&some_array[1] == ptr_val);
    assert(&some_array[4] == atom_ptr.load());
}
} // example_01


#include <iostream>
int main() {
    std::cout << "[ok] - example 01" << std::endl; example_01::run(); std::cout << std::endl;
    
    return 0;
}

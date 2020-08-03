#include <atomic>
#include <memory>
#include <cassert>
namespace example_01 { // base usage of std::atomic<T*>
    
struct foo { int val = 0; };
    
std::shared_ptr<foo> ptr{ new foo{} };
    
void process_global_data() {
    {
    std::shared_ptr<foo> local{ std::atomic_load(&ptr) };
    local->val = 42;
    }
    
    assert(42 == std::atomic_load(&ptr)->val);
}
    
void update_global_data() {
    {
    std::shared_ptr<foo> local{ new foo{} };
    local->val = 17;
    std::atomic_store(&ptr, local);
    }
    
    assert(17 == std::atomic_load(&ptr)->val);
}
    
void run() {
    process_global_data();
    update_global_data();    
}
} // example_01


#include <iostream>
int main() {
    std::cout << "[ok] - example 01" << std::endl; example_01::run(); std::cout << std::endl;
    
    return 0;
}

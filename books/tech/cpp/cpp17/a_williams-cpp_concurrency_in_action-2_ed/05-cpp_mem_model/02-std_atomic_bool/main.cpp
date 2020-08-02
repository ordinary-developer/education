#include <functional>
#include <random>
namespace { // util func
bool rand_bool() {
    return std::bind(
        std::uniform_int_distribution<>{ 0, 1 },
        std::default_random_engine{})();
}    
} // anonymous namespace


#include <atomic>
#include <iostream>
#include <cassert>
namespace example_01 { // asignment operator for std::atomic<bool>
void run() {
    std::atomic<bool> atom_val{true};
    bool const val = (atom_val = false);
    assert(not val and not atom_val);
}    
} // example_01


#include <atomic>
#include <iostream>
#include <cassert>
namespace example_02 { // "load" and "store" operations for std::atomic<bool>
void run() {
    std::atomic<bool> atom_val{};
    
    {
    assert(not atom_val.load());
    }
    
    {
    atom_val.store(true);
        
    bool const val_before = atom_val.exchange(false);
    bool const val_after = atom_val;
            
    assert(val_before);
    assert(not val_after);
    }
}    
} // example_02


namespace example_03 { // "compare_exchange_weak" using
void run() {
    bool expected = false;
    std::atomic<bool> atom_val{ rand_bool() };
    while (not atom_val.compare_exchange_weak(expected, true) and not expected);
    assert(atom_val);
}    
} // example_03


#include <atomic>
#include <cassert>
namespace example_04 {
void run() {
    std::atomic<bool> atom_val{};
    bool expected{};
    
    atom_val.store(rand_bool());
    expected = false;
    while (
        not atom_val.compare_exchange_weak(expected, true,
            std::memory_order_acq_rel, std::memory_order_acquire)
        and not expected
    ) {}
    assert(atom_val);
    
    atom_val.store(rand_bool());
    expected = false;
    while (
        not atom_val.compare_exchange_weak(
            expected, true, std::memory_order_acq_rel)
        and not expected
    ) {}
    assert(atom_val);
}    
} // example_04


#include <iostream>
int main() {
    std::cout << "[ok] - example_01" << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "[ok] - example_02" << std::endl; example_02::run(); std::cout << std::endl;
    std::cout << "[ok] - example_03" << std::endl; example_03::run(); std::cout << std::endl;
    std::cout << "[ok] - example_04" << std::endl; example_04::run(); std::cout << std::endl;
    
    return 0;
}
#include <functional>
#include <random>
namespace { // utilities
bool rand_bool() {
    auto gen = std::bind(
        std::uniform_int_distribution<>{ 0, 1 },
        std::default_random_engine{});
    return gen();
}

} // anonymous

#include <atomic>
#include <iostream>
#include <cassert>
namespace example_01 { // assignment operator for std::atomic<bool>
void run() {
    std::atomic<bool> atom_val{true};
    bool const val = (atom_val = false);
    assert(false == val);
}    
} // example_01


#include <atomic>
#include <iostream>
#include <cassert>
namespace example_02 { // "load" and "store" operations for std::atomic<bool>
void run() {
    std::atomic<bool> atom_val{};

    {
        bool const val = atom_val.load(std::memory_order_acquire);
        assert(not val);
    }

    {
        atom_val.store(true);
        bool const val_before = atom_val.exchange(false, std::memory_order_acq_rel);
        bool const val_after = atom_val;
        assert(val_before);
        assert(not val_after);
    }
}
} // example_02


#include <atomic>
#include <cassert>
namespace example_03 { // "compare_exchange_weak" using
void run() {
    bool expected = false;
    std::atomic<bool> atom_val{ rand_bool() };
    while(not atom_val.compare_exchange_weak(expected, true) and not expected);
    assert(atom_val);
}
} // example_03


#include <atomic>
#include <cassert>
namespace example_04 { // "compare_exchange_weak" with memor ordering
void run() {
    std::atomic<bool> atom_val{};
    bool expected{};

    atom_val.store(rand_bool());
    expected = false;
    while (
        not atom_val.compare_exchange_weak(expected, true,
            std::memory_order_acq_rel, std::memory_order_acquire)
        and not expected) {}
    assert(atom_val);

    atom_val.store(rand_bool());
    expected = false;
    while (
        not atom_val.compare_exchange_weak(
            expected, true, std::memory_order_acq_rel)
        and not expected) {}            
    assert(atom_val);
}

} // example_04


#include <iostream> 
int main() {
    std::cout << "example_01 => [OK]"; example_01::run(); std::cout << "\n\n";
    std::cout << "example_02 => [OK]"; example_02::run(); std::cout << "\n\n";
    std::cout << "example_03 => [OK]"; example_03::run(); std::cout << "\n\n";
    std::cout << "example_04 => [OK]"; example_04::run(); std::cout << "\n\n";

    return 0;
}

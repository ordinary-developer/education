#include <atomic>
#include <cassert>
namespace example_01 { // base usage of std::atomic<T*>
void run() {
    class Foo {};    

    Foo some_array[5];
    std::atomic<Foo*> atomic_pointer{some_array};
    Foo *pointer_val{nullptr};

    pointer_val = atomic_pointer.fetch_add(2);
    assert(some_array == pointer_val);
    assert(&some_array[2] == atomic_pointer.load());

    pointer_val = (atomic_pointer -= 1);
    assert(&some_array[1] == pointer_val);
    assert(&some_array[1] == atomic_pointer.load());

    pointer_val = atomic_pointer.fetch_add(3, std::memory_order_release);
    assert(&some_array[1] == pointer_val);
    assert(&some_array[4] == atomic_pointer.load());
}
} // example_01

#include <iostream>
int main() {
    std::cout << "example 01 => [OK]"; example_01::run(); std::cout << "\n\n";

    return 0;
}

#include <atomic>
#include <memory>
#include <cassert>
namespace example_01 { // using atomic operations for std::shared_ptr

struct Foo { int val_ = 0; };

std::shared_ptr<Foo> pointer{ new Foo{} };

void process_global_data() {
    std::shared_ptr<Foo> local{ std::atomic_load(&pointer) };
    local->val_ = 42;

    assert(42 == std::atomic_load(&pointer)->val_);
}

void update_global_data() {
    std::shared_ptr<Foo> local{ new Foo{} };
    local->val_ = 42;
    assert(42 == std::atomic_load(&pointer)->val_);
    std::atomic_store(&pointer, local);

    assert(42 == std::atomic_load(&pointer)->val_);
}

void run() {
    process_global_data();
    update_global_data();
}
} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 => [OK]"; example_01::run(); std::cout << std::endl << std::endl;

    return 0;
}

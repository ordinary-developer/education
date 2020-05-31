#include <atomic>
#include <thread>
#include <cassert>
namespace example_01 {  // acquire-release and relaxed orederings

std::atomic<bool> x{}, y{};
std::atomic<int> z{};

void write_x_then_y() {
    x.store(true, std::memory_order_relaxed);
    y.store(true, std::memory_order_release);
}

void read_y_then_x() {
    while (not y.load(std::memory_order_acquire));
    if (x.load(std::memory_order_relaxed))
        ++z;
}

void run() {
    x = false, y = false, z = 0;
    std::thread t1{ write_x_then_y }, t2{ read_y_then_x };
    t1.join(); t2.join();

    assert(0 != z.load());
}

} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 => [OK]"; example_01::run(); std::cout << std::endl << std::endl;

    return 0;
}

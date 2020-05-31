#include <atomic>
#include <iostream>
#include <thread>
#include <cassert>
namespace example_01 {  // no total ordering for acquire-release operations

std::atomic<bool> x{}, y{};
std::atomic<int> z{};

void write_x() { x.store(true, std::memory_order_release); }
void write_y() { y.store(true, std::memory_order_release); }

void read_x_then_y() {
    while (not x.load(std::memory_order_acquire));
    if (y.load(std::memory_order_acquire))
        ++z;
}

void read_y_then_x() {
    while (not y.load(std::memory_order_acquire));
    if (x.load(std::memory_order_acquire))
        ++z;
}

void run() {
    x = false, y = false, z = 0;
    std::thread t1{ write_x }, t2{ write_y }, t3{ read_x_then_y }, t4{ read_y_then_x };
    t1.join(); t2.join(); t3.join(); t4.join();

    // z can be equal to 0
    std::cout << std::endl << "z = " << z.load() << std::endl;
}

} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 => [OK]"; example_01::run(); std::cout << std::endl << std::endl;

    return 0;
}

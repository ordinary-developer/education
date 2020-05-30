#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <cassert>
namespace example_01 { // using atomic operations for std::shared_ptr

void show(const int a, const int b) {
    std::cout << a << ", " << b << std::endl;
}

int get_num() {
    static int i{0};
    return ++i;
}
void run() {
    show(get_num(), get_num());
}
} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 => [OK]" << std::endl; example_01::run(); std::cout << std::endl << std::endl;

    return 0;
}

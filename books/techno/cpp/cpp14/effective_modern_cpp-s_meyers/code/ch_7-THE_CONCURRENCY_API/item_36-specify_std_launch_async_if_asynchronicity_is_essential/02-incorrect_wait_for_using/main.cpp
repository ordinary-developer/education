#include <future>
#include <iostream>
using namespace std::literals;

void f() {
    std::this_thread::sleep_for(1s);
}

int main() {
    auto fut = std::async(f);
    while (fut.wait_for(100ms) != std::future_status::ready) {
        std::cout << "Waiting ..." << std::endl;
    }
    return 0;
}

#include <future>
#include <iostream>

using namespace std::literals;

void f() { 
    std::this_thread::sleep_for(1s);
}

int main() {
    auto fut = std::async(f);

    if (fut.wait_for(0s) == std::future_status::deferred) {
        std::cout << "begin getting a future ..." << std::endl;
        fut.get();
        std::cout << "end getting a future ..." << std::endl;
    }
    else {
        while (fut.wait_for(100ms) != std::future_status::ready) {
            std::cout << "Waiting...";
        }
    }

    return 0;
}

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::literals;


int main() {
    std::jthread nonInterruptable([] {
        int counter{0};
        while (counter < 10) {
            std::this_thread::sleep_for(0.2s);
            std::cout << "nonInterruptable: " << counter << '\n';
            ++counter;
        }
    });

    std::jthread interruptable([](std::stop_token stoken) {
        int counter{0};
        while (counter < 10) {
            std::this_thread::sleep_for(0.2s);
            if (stoken.stop_requested()) {
                return;
            }
            std::cout << "interruptable: " << counter << '\n';
            ++counter;
        }
    });

    std::this_thread::sleep_for(1s);
    
    std::cout << '\n';
    std::cout << "Main thread interrupts both jthreads" << '\n';

    nonInterruptable.request_stop();
    interruptable.request_stop();

    std::cout << "ok" << std::endl;
}

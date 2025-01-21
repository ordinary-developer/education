#include <chrono>
#include <iostream>
#include <thread>

using namespace std::literals;


void func(std::stop_token stopToken) {
    std::this_thread::sleep_for(100ms);
    for (int i = 0; i <= 9; ++i) {
        std::stop_callback callbac(stopToken, [i] { std::cout << i; });
    }

    std::cout << std::endl;
}


int main() {
    std::jthread t1 = std::jthread(func);
    std::jthread t2 = std::jthread(func);
    t1.request_stop();
    t2.request_stop();

    std::cout << std::endl;
}

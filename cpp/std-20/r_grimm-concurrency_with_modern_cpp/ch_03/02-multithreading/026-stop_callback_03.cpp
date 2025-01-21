#include <chrono>
#include <functional>
#include <iostream>
#include <list>
#include <stop_token>
#include <thread>

using namespace std::literals;


using handler_t = std::function<void()>;
using callback_t = std::stop_callback<handler_t>;

void func(std::stop_token stopToken) {
    std::list<callback_t> callbacks;
    for (int i = 0; i <= 9; ++i) {
        callbacks.emplace_back(stopToken, [i] { std::cout << i; });
    }
    std::this_thread::sleep_for(100ms);
    std::cout << std::endl;
}


int main() {
    std::jthread t1 = std::jthread(func);
    std::jthread t2 = std::jthread(func);
    std::this_thread::sleep_for(50ms);
    t1.request_stop();
    t2.request_stop();

    std::cout << std::endl;
}

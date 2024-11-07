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
    std::cout << '\n';
}


int main() {
    std::cout << '\n';

    std::jthread thr1 = std::jthread(func);
    std::jthread thr2 = std::jthread(func);
    std::this_thread::sleep_for(50ms);
    thr1.request_stop();
    thr2.request_stop();

    std::cout << '\n';
}

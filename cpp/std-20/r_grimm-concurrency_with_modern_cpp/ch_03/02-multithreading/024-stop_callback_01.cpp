#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::literals;


auto func = [](std::stop_token stoken) {
    int counter{0};
    auto threadId = std::this_thread::get_id();
    std::stop_callback callback(stoken, [&counter, threadId] {
        std::cout << "Thread id: " << threadId
                  << "; counter: " << counter << std::endl;
    });
    while (counter < 10) {
        std::this_thread::sleep_for(0.2s);
        ++counter;
    }
};


int main() {
    std::vector<std::jthread> vecThreads(10);
    for (auto & t : vecThreads)
        t = std::jthread(func);

    std::this_thread::sleep_for(1s);

    for (auto & t : vecThreads)
        t.request_stop();

    std::cout << std::endl;
}

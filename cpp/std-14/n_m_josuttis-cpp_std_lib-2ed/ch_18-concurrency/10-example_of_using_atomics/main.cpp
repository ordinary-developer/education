#include <atomic>
#include <future>
#include <thread>
#include <chrono>
#include <iostream>

long data{};
std::atomic<bool> readyFlag{ false };

void provider() {
    std::cout << "<return>" << std::endl;
    std::cin.get();

    data = 42;

    readyFlag.store(true);
}

void consumer() {
    while (not readyFlag.load()) {
        std::cout.put('.').flush();
        std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
    }
    std::cout << "\nvalue : " << data << std::endl;
}


int main() {
    auto p = std::async(std::launch::async, provider);
    auto c = std::async(std::launch::async, consumer);

    return 0;
}

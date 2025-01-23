#include <iostream>
#include <chrono>
#include <future>
#include <thread>


int main() {
    auto _ = std::async(std::launch::async, []{
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "[ .... ] first thread" << std::endl;
    });
    (void)_;

    auto __ = std::async(std::launch::async, []{
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "[ .... ] second thread" << std::endl;
    });
    (void)__;

    std::cout << "[ .... ] main thread" << std::endl;
}

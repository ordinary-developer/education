#include <chrono>
#include <iostream>
#include <future>
#include <thread>

int main() {
    std::cout << std::endl;

    std::async(std::launch::async, [] {
        std::this_thread::sleep_for(std::chrono::seconds{2});
        std::cout << "first thread" << std::endl;
    });

    std::async(std::launch::async, []{
        std::this_thread::sleep_for(std::chrono::seconds{1});
        std::cout << "second thread" << std::endl;
    });

    std::cout << "main thread" << std::endl;

    std::cout << std::endl;
}

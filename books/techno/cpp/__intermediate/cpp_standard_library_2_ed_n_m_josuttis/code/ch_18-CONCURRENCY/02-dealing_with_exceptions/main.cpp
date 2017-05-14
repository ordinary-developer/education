#include <thread>
#include <chrono>
#include <exception>
#include <future>
#include <iostream>


void task1() {
    std::this_thread::sleep_for(std::chrono::milliseconds{ 2000 });
    throw std::bad_alloc{};
}

int main() {
    std::cout << "[OK] " << "starting, press <return> to continue ..." 
              << std::endl;

    std::future<void> f1{ std::async(std::launch::deferred, task1) };
    std::cin.get();
    std::cout << "[INFO] " << "waiting for the end of task1 ..." 
              << std::endl;
    try {
        f1.get();
    }
    catch (std::exception const& e) {
        std::cerr << "[EXCEPTION] " << e.what() << std::endl;
    }

    return 0;
}

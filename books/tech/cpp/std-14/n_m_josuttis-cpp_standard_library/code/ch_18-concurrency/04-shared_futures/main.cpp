#include <iostream>
#include <stdexcept>
#include <future>
#include <thread>
#include <exception>


int queryNumber() {
    std::cout<< "read number: ";
    int number{};
    std::cin >> number;

    if (not number)
        throw std::runtime_error{ "no number read" };

    return number;
}

void doSomething(char c, std::shared_future<int> f) {
    try {
        int number{ f.get() };
        for (int i{0}; i < number; ++i) {
            std::this_thread::sleep_for(
                                std::chrono::milliseconds{100});
            std::cout.put(c).flush();
        }
    }
    catch (std::exception const& e) {
        std::cerr << "[EXCEPTION] in thread " 
                  << std::this_thread::get_id() << ": " << e.what()
                  << std::endl;
    }
}

int main() {
    try {
        std::shared_future<int> f{ std::async(queryNumber) };

        std::future<void> f1{ std::async(std::launch::async,
                                         doSomething, '1', f) };
        std::future<void> f2{ std::async(std::launch::async,
                                         doSomething, '2', f) };
        std::future<void> f3{ std::async(std::launch::async,
                                         doSomething, '3', f) };

        f1.get();
        f2.get();
        f3.get();
    }
    catch (std::exception const& e) {
        std::cout << "[EXCEPTION] " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "[OK] done" << std::endl;
    return 0;
}

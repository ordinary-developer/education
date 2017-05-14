#include <random>
#include <thread>
#include <chrono>
#include <iostream>
#include <future>

int doSomething(char c) {
    std::default_random_engine randomEngine{c};
    std::uniform_int_distribution<int> distribution{10, 1000};
    
    for (int i{0}; i < 10; ++i) {
        std::this_thread::sleep_for(
            std::chrono::milliseconds{ distribution(randomEngine) });
        std::cout.put(c).flush();
    }

    return c;
}

int func1() { return doSomething('1'); }
int func2() { return doSomething('2'); }


int main() {
    std::cout << "[OK] starting: " << std::endl;

    std::future<int> result1{ std::async(func1) };
    int result2{ func2() };
    int result{ result1.get() + result2 };

    std::cout << std::endl;
    std::cout << "[OK] result: " << result << std::endl;

    return 0;
}

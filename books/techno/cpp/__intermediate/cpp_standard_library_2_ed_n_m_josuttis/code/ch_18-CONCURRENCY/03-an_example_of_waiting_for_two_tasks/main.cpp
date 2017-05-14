#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

void doSomething(char c) {
    std::default_random_engine randomEngine{c};
    std::uniform_int_distribution<int> distribution{10, 1000};
    for (int i{0}; i < 10; ++i) {
        std::this_thread::sleep_for(
            std::chrono::milliseconds{ distribution(randomEngine) });
        std::cout.put(c).flush();
    }
}

int main() {
    std::cout << "[OK] starting" << std::endl;

    std::future<void> f1{ std::async(std::launch::async,
                                     []{ doSomething('1'); }) };
    std::future<void> f2{ std::async(std::launch::async,
                                     []{ doSomething('2'); }) };
    
    if (std::future_status::deferred !=
            f1.wait_for(std::chrono::seconds(0)) 
        or         
        std::future_status::deferred != 
            f2.wait_for(std::chrono::seconds(0)))
    {
        while (std::future_status::ready !=
                    f1.wait_for(std::chrono::seconds(0))
               and
               std::future_status::ready !=
                    f2.wait_for(std::chrono::seconds(0)))
        {
            std::this_thread::yield();
        }
    }

    std::cout << std::endl << "[INFO] " << "after waiting"  << std::endl;

    try {
        f1.get();
        f2.get();
    }
    catch (std::exception const& e) {
        std::cout << "[EXCEPTION] " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "[OK] " << "done" << std::endl;

    return 0;
}

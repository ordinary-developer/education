#include <atomic>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

int main() {
    std::cout << '\n';

    std::atomic<std::shared_ptr<std::string>> sharedStr(
        std::make_shared<std::string>("Zero"));

    std::thread t1([&sharedStr] {
        sharedStr.store(std::make_shared<std::string>(*sharedStr.load() + "One"));
    });
    std::thread t2([&sharedStr] {
        sharedStr.store(std::make_shared<std::string>(*sharedStr.load() + "Two"));    
    });
    std::thread t3([&sharedStr] {
        sharedStr.store(std::make_shared<std::string>(*sharedStr.load() + "Three"));
    });
    std::thread t4([&sharedStr] {
        sharedStr.store(std::make_shared<std::string>(*sharedStr.load() + "Four"));
    });
    std::thread t5([&sharedStr] {
        sharedStr.store(std::make_shared<std::string>(*sharedStr.load() + "Five"));
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << *sharedStr.load() << '\n';

    std::cout << '\n';
}

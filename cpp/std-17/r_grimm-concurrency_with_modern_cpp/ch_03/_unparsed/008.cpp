#include <iostream>
#include <memory>
#include <thread>
#include <vector>


int main() {
    std::vector<std::thread> threads{};

    std::shared_ptr<int> ptr = std::make_shared<int>(2011);
    for (auto i = 0; i < 10; i++) {
        threads.emplace_back(std::thread([ptr] {
            std::shared_ptr<int> localPtr{ptr};
            localPtr = std::make_shared<int>(2014);
        }));  
    }

    for (auto & t : threads)
        if (t.joinable())
            t.join();
}

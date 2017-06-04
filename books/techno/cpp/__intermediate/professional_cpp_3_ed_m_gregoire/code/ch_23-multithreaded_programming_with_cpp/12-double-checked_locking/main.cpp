#include <atomic>
#include <mutex>
#include <iostream>
#include <thread>
#include <vector>

void initializeSharedResources() {
    std::cout << "Shared resources initialized." << std::endl;
}

std::atomic<bool> initialized{false};
std::mutex mutex{};

void function() {
    if (!initialized) {
        std::unique_lock<std::mutex> lock{mutex};
        if (!initialized) {
            initializeSharedResources();
            initialized = true;
        }
    }
    std::cout << "OK" << std::endl;
}

int main() {
    std::vector<std::thread> threads{};

    for (int i{0}; i < 5; ++i) 
        threads.push_back(std::thread{function});

    for (auto& thread : threads) 
        thread.join();

    return 0;
}

#include <atomic>
#include <iostream>
#include <memory>
#include <thread>

int main() {
    std::shared_ptr<int> ptr = std::make_shared<int>(2011);

    for (auto i = 0; i < 10; i++) {
        std::thread([&ptr] () mutable {
            std::shared_ptr<int> localPtr(ptr);
            std::atomic_store(&ptr, localPtr);
        }).detach();
    }
}

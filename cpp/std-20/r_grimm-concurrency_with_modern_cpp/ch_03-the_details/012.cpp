#include <atomic>
#include <iostream>
#include <thread>
#include <vector>


std::vector<int> mySharedWork{};
std::atomic<bool> dataProduced{false};
std::atomic<bool> dataConsumed{false};

void dataProducer() {
    mySharedWork = { 1, 0, 3};
    dataProduced.store(true, std::memory_order_release);
}

void deliverBoy() {
    while (not dataProduced.load(std::memory_order_acquire));
    dataConsumed.store(true, std::memory_order_release);
}

void dataConsumer() {
    while (not dataConsumed.load(std::memory_order_acquire));
    mySharedWork[1] = 2;
}


int main() {
    std::cout << std::endl;

    std::thread t1{dataConsumer};
    std::thread t2{deliverBoy};
    std::thread t3{dataProducer};

    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.join();

    if (t3.joinable())
        t3.join();

    for (const auto v : mySharedWork)
        std::cout << v << " ";

    std::cout << "\n\n";
}

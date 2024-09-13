#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std::chrono_literals;


std::atomic<int> atom{0};
int somethingShared{0};

void writeShared() {
    somethingShared = 2011;
    atom.store(2, std::memory_order_release);
}

void readShared() {
    while (not (atom.fetch_sub(1, std::memory_order_acquire) > 0))
        std::this_thread::sleep_for(100ms);

    std::cout << "somethingShared: " << somethingShared << std::endl;
}


int main() {
    std::cout << std::endl;

    std::thread t1{writeShared};
    std::thread t2{readShared};
    std::thread t3{readShared};

    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.join();

    if (t3.joinable())
        t3.join();

    std::cout << "atom: " << atom << std::endl;
    std::cout << std::endl;
}

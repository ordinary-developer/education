#include <atomic>
#include <thread>
#include <iostream>
#include <mutex>

std::atomic<int> atom{0};
int somethingShared{0};

using namespace std::chrono_literals;

void writeShared() {
    somethingShared = 2011;
    atom.store(2, std::memory_order_release);
}

void readShared() {
    while (not (atom.fetch_sub(1, std::memory_order_acquire))) {
        std::this_thread::sleep_for(100ms);
    }
    
    std::cout << "somethingShared: " << somethingShared << '\n';
}

int main() {
    std::cout << '\n';
    
    std::thread t1(writeShared);
    std::thread t2(readShared);
    std::thread t3(readShared);
    
    t1.join();
    t2.join();
    t3.join();
    
    std::cout << "atom: " << atom << '\n';
    
    std::cout << '\n';
}

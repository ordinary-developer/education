#include <atomic>
#include <iostream>
#include <string>
#include <thread>


std::atomic<std::string*> ptr{};
int data{};
std::atomic<int> atomData{};

void producer() {
    std::string * p = new std::string("C++11");
    data = 2011;
    atomData.store(2014, std::memory_order_relaxed);
    ptr.store(p, std::memory_order_release);
}

void consumer() {
    std::string * p2{};
    while (not (p2 = ptr.load(std::memory_order_acquire)));
    std::cout << "*p2: " << *p2 << std::endl;
    std::cout << "data: " << data << std::endl;
    std::cout << "atomData: " << atomData.load(std::memory_order_relaxed) << std::endl;
}

int main() {
    std::cout << std::endl;

    std::thread t1{producer};
    std::thread t2{consumer};

    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.join();

    std::cout << std::endl;
}
    
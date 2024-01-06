#include <atomic>
#include <thread>
#include <iostream>
#include <string>


std::atomic<std::string*> ptr{};
int data{};
std::atomic<int> atoData{};

void producer() {
    std::string * p = new std::string("C++");
    data = 2011;
    atoData.store(2014, std::memory_order_relaxed);
    ptr.store(p, std::memory_order_release);
}

void consumer() {
    std::string * p2{};
    while (not (p2 = ptr.load(std::memory_order_acquire)));
    std::cout << "*p2: " << *p2 << std::endl;
    std::cout << "data: " << data << std::endl;
    std::cout << "atoData: " << atoData.load(std::memory_order_relaxed) << std::endl;
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

#include <iostream>
#include <thread>
#include <mutex>


std::once_flag onceFlag;

void doOnce() {
    std::call_once(onceFlag, []() { std::cout << "Only once." << std::endl; });
}

void doOnce2() {
    std::call_once(onceFlag, []() { std::cout << "Only once2" << std::endl; });
}


int main() {
    std::cout << std::endl;

    std::thread t1(doOnce);
    std::thread t2(doOnce);
    std::thread t3(doOnce2);
    std::thread t4(doOnce2);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << std::endl;
}

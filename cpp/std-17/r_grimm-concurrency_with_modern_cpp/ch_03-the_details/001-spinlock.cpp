#include <atomic>
#include <iostream>
#include <thread>


class Spinlock {
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
    void lock() {
        while (flag.test_and_set());
    }

    void unlock() {
        flag.clear();
    }
};


Spinlock spinlock{};

void workOnRes() {
    spinlock.lock();
    std::cout << "working on resources..." << std::endl;
    spinlock.unlock();
}


int main(){
    std::thread t1(workOnRes);
    std::thread t2(workOnRes);
    t1.join();
    t2.join();

    return 0;
}

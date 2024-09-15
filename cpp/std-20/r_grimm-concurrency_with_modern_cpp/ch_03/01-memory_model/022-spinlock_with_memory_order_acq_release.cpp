#include <atomic>
#include <iostream>
#include <thread>

class Spinlock {
    std::atomic_flag flag;
    
public:
    Spinlock() : flag(ATOMIC_FLAG_INIT) {}
    
    void lock() {
        while (flag.test_and_set(std::memory_order_acquire));
    }
    
    void unlock() {
        flag.clear(std::memory_order_release);
    }
};

Spinlock spin;

void workOnRes() {
    spin.lock();
    std::cout << std::showbase << std::hex << std::this_thread::get_id() << std::endl;    
    spin.unlock();
}

int main() {
    std::thread t1(workOnRes);
    std::thread t2(workOnRes);
    t1.join();
    t2.join();
    
    std::cout << "ok" << std::endl;
}

#include <atomic>
#include <thread>
#include <cassert>
namespace workspace {

std::atomic<int> data{0};
std::atomic<bool> sync1{false}, sync2{false};

void thread_1() {
    data.store(42, std::memory_order_relaxed);
    sync1.store(true, std::memory_order_release);
}

void thread_2() {
    while (not sync1.load(std::memory_order_acquire));
    sync2.store(true, std::memory_order_release);
}

void thread_3() {
    while (not sync2.load(std::memory_order_acquire));

    assert(42 == data);
}

    
void run() {
    std::thread t1{ thread_1 }, t2{ thread_2 }, t3{ thread_3 };
    t1.join(), t2.join(), t3.join();
}
} // workspace


int main() {
    workspace::run();

    return 0;
}

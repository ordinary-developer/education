#include <algorithm>
#include <atomic>
#include <iostream>
#include <list>
#include <mutex>
#include <thread>

namespace { // spinlock declaration
class spinlock_mutex {
    std::atomic_flag flag_;
public:
    spinlock_mutex() : flag_{ ATOMIC_FLAG_INIT } {} 
    void lock() { while(flag_.test_and_set(std::memory_order_acquire)); }
    void unlock() { flag_.clear(std::memory_order_release); }
};    

} // anonymous namespace

std::list<int> l{};
spinlock_mutex mut{};

void add_to_list(int const val) { 
    std::lock_guard<spinlock_mutex> guard{mut};
    l.push_back(val);
}

bool list_contains(int const val) {
    std::lock_guard<spinlock_mutex> guard{mut};
    return std::cend(l)
        != std::find(std::cbegin(l), std::cend(l), val);
}

void thread_func() {
    add_to_list(1);
    add_to_list(2);
    add_to_list(3);
}

int main() {
    std::thread t{thread_func};
    auto const is_val_contained = list_contains(1);
    t.join();

    std::cout << is_val_contained << std::endl;

    return 0;
}
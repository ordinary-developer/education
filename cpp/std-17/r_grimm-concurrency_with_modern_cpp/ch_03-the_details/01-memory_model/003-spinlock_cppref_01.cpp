#include <atomic>
#include <iostream>
#include <thread>
#include <vector>


std::atomic_flag lock = ATOMIC_FLAG_INIT;

void f(const int n) {
    for (int cnt = 0; cnt < 40; ++cnt) {
        while (lock.test_and_set(std::memory_order_acquire)) {
#if defined(__cpp_lib_atomic_flag_test)
            while (lock.test(std::memory_order_relaxed));
#endif       
        }
    
        static int out{};
        std::cout << n << ((++out % 40) == 0 ? '\n' : ' ');
        lock.clear(std::memory_order_release);
    }
}


int main() {    
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n)
        v.emplace_back(f, n);
    for (auto& t : v)
        t.join();
}

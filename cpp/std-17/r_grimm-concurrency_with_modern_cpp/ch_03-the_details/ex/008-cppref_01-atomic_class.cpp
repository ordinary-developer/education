#include <atomic>
#include <iostream>
#include <thread>
#include <vector>


std::atomic_int acnt;
int cnt;

void f() {
    for (int n = 0; n < 10000; ++n) {
        ++acnt;
        ++cnt;
    }
}

int main() {
    {
        std::vector<std::jthread> pool;
        for (int n = 0; n < 10; ++n) {
            pool.emplace_back(f);
        }
    }

    std::cout << "The atomic counter is " << acnt << '\n'
              << "The non-atomic counter is " << cnt << '\n';
}

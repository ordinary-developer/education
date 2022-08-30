#include <atomic>
#include <iostream>
#include <thread>
#include <vector>


std::atomic<int> count{0};

void add() {
    for (int n{0}; n < 1000; ++n)
        count.fetch_add(1, std::memory_order_relaxed);
}


int main() {
    std::vector<std::thread> v{};
    
    for (int n{0}; n < 10; ++n)
        v.emplace_back(add);

    for (auto & t : v)
        if (t.joinable())
            t.join();

    std::cout << "Final counter value is " << count << '\n';
}
    
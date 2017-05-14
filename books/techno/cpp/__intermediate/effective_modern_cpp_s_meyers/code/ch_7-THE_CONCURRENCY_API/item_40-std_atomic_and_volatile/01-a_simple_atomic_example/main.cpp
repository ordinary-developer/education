#include <atomic>
#include <iostream>

int main() {
    std::atomic<int> ai(0);
    ai = 10;
    std::cout << ai;
    ++ai;
    --ai;

    return 0;
}

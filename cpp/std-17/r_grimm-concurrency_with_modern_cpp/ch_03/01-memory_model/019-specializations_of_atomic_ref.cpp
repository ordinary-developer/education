#include <atomic>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

struct Counter {
    int a;
    int b;
};

int main()
{
    Counter counter;
    std::atomic_ref<Counter> cnt(counter);

    return 0;
}

#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>

constexpr long long size = 10000000;

constexpr long long fir = 2500000;
constexpr long long sec = 5000000;
constexpr long long thi = 7500000;
constexpr long long fou = 10000000;

void sumUp(std::atomic<unsigned long long> & sum, const std::vector<int> & val,
           unsigned long long beg, unsigned long long end)
{
    for (auto it = beg; it < end; ++it) {
        sum += val[it];
    }
}


int main() {
    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < size; ++i) {
        randValues.push_back(uniformDist(engine));
    }

    std::atomic<unsigned long long> sum = {};   

    const auto sta = std::chrono::steady_clock::now();

    std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, fir);
    std::thread t2(sumUp, std::ref(sum), std::ref(randValues), fir, sec);
    std::thread t3(sumUp, std::ref(sum), std::ref(randValues), sec, thi);
    std::thread t4(sumUp, std::ref(sum), std::ref(randValues), thi, fou);

    t1.join(); t2.join(); t3.join(); t4.join();

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for addtion " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;   

    std::cout << std::endl;
}

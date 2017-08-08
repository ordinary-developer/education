#include <random>
#include <iostream>
namespace example1 {
void run() {
    std::random_device randomDevice{};
    std::mt19937 engine{ randomDevice() };
    std::uniform_int_distribution<int> distribution{1, 99};
    std::cout << distribution(engine) << std::endl;
}
}


#include <random>
#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
namespace example2 {
void run() {
    std::random_device randomDevice{};
    std::mt19937 engine{ randomDevice() };
    std::uniform_int_distribution<int> distribution{ 1, 99 };
    auto generator = std::bind(distribution, engine);
    std::vector<int> vec(10);
    std::generate(std::begin(vec), std::end(vec), generator);
    for (auto i : vec)
        std::cout << i << " ";
}
}

#include <random>
#include <vector>
#include <algorithm>
namespace example3 {

template <typename T>
void fillVector(std::vector<int>& vec, T randomGenerator) {
    std::generate(std::begin(vec), std::end(vec), randomGenerator);
}

void run() {
    std::random_device randomDevice{};
    std::mt19937 engine{ randomDevice() };
    std::uniform_int_distribution<int> distribution{ 1, 99 };
    auto generator = std::bind(distribution, engine);
    std::vector<int> vec(10);
    fillVector(vec, generator);
    for (auto i : vec) 
        std::cout << i << " ";
}
}

int main() {
    example1::run();
    example2::run();
    example3::run();


    return 0;
}

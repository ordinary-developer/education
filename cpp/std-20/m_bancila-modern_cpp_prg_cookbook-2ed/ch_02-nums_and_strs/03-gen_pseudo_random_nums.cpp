#include <iostream>
#include <random>
namespace example_01 { // -> the "how to do it" section

void run() {
    std::random_device rd{};
    auto mtgen = std::mt19937{ rd() };
    auto ud = std::uniform_int_distribution<>{ 1, 6 };
    for (auto i = 0; i < 20; ++i) {
        auto number = ud(mtgen);
        std::cout << number << " ";
    }
}
    
} // example 01


#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <random>
#include <cmath>
namespace example_02 { // -> the "how it works" section

void generate_and_print(std::function<int(void)> gen, int const iterations = 10000) {
    auto data = std::map<int, int>{};
    
    for (auto n = 0; n < iterations; ++n)
        ++data[gen()];
    
    auto max = std::max_element(std::cbegin(data), std::cend(data), 
        [](auto kvp1, auto kvp2) { return kvp1.second < kvp2.second; });
        
    for (auto i = max->second / 200; i > 0; --i) {
        for (auto kvp : data) {
            std::cout 
                << std::fixed << std::setprecision(1) << std::setw(3)
                << (kvp.second / 200 >= i ? (char)124 : ' ');
        }
        
        std::cout << '\n';
    }
    
    for (auto kvp : data) 
        std::cout 
            << std::fixed << std::setprecision(1) << std::setw(3)
            << kvp.first;
    std::cout << '\n'; 
}

void run() {
    {
        auto mtgen = std::mt19937{};
        for (auto i = 0; i < 10; ++i)
            std::cout << mtgen() << " "; 
        std::cout << std::endl;
    }
    {
        auto seed = std::chrono::high_resolution_clock::now()
            .time_since_epoch()
            .count();
        auto mtgen = std::mt19937{ static_cast<unsigned int>(seed) };
        for (auto i = 0; i < 10; ++i)
            std::cout << mtgen() << " ";
        std::cout << std::endl;
    }    
    
    {
        std::random_device rd{};
        auto mtgen = std::mt19937{ rd() };
        for (auto i = 0; i < 10; ++i)
            std::cout << mtgen() << " ";
        std::cout << std::endl;
    }
    
    {
        std::random_device rd{};
        auto mtgen = std::mt19937{ rd() };
        auto ud = std::uniform_int_distribution<>{ 1, 6 };
        generate_and_print([&mtgen, &ud]() { return ud(mtgen); });
    }
    
    {
        std::random_device rd{};
        auto mtgen = std::mt19937{ rd() };
        auto nd = std::normal_distribution<>{ 5, 2 };
        generate_and_print([&mtgen, &nd]() {
            return static_cast<int>(std::round(nd(mtgen)));
        });
    }
}
   
} // example_02

int main() {
    std::cout << "example 01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "example 02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl << std::endl;
    
	return 0;
}

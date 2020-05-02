#include <random>
#include <iostream>
namespace example_01 {
void run() {
    std::random_device rd{};
    auto mtgen = std::mt19937{rd()};   
    auto ud = std::uniform_int_distribution<>{1, 6};
    for (auto i{0}; i < 20; ++i)
        std::cout << ud(mtgen) << " ";
}
} // example_01


#include <random>
#include <iostream>
namespace example_02 {
void run() {
    auto mtgen = std::mt19937{};
    for (auto i{0}; i < 10; ++i)
        std::cout << mtgen() << std::endl;
}
} // example_02


#include <random>
#include <chrono>
#include <iostream>
namespace example_03 {
void run() {
    auto const seed = std::chrono::high_resolution_clock::now()
                            .time_since_epoch()
                            .count();
    auto mtgen = std::mt19937{ static_cast<unsigned int>(seed) };
    for (auto i{0}; i < 10; ++i)
        std::cout << mtgen() << std::endl;
}
} // example_03


#include <random>
#include <chrono>
#include <iostream>
namespace example_04 {
void run() {
    std::random_device rd;
    auto mtgen = std::mt19937{ rd() };
    for (auto i{0}; i < 10; ++i)
        std::cout << mtgen() << std::endl;
}    
} // example_04


#include <random>
#include <functional>
#include <map>
#include <iomanip>
#include <iostream>
namespace example_05 {
    
void generate_and_print(
    std::function<int(void)> gen,
    int const iterations = 10000)
{
    auto data = std::map<int, int>{};
    
    for (auto n{0}; n < iterations; ++n)
        ++data[gen()];
    
    auto max = std::max_element(
        std::begin(data), std::end(data), 
        [](auto kvp1, auto kvp2) { return kvp1.second < kvp2.second; });
    
    for (auto i{ max->second / 200}; i > 0; --i) {
        for (auto kvp : data) {
            std::cout << std::fixed << std::setprecision(1) << std::setw(3)
                << (kvp.second / 200 >= i ? (char)219 : ' ');
        }
        std::cout << std::endl;
    }
    
    for (auto kvp : data)
        std::cout << std::fixed << std::setprecision(1) << std::setw(3) << kvp.first;
    
    std::cout << std::endl;
}
    
void run() {
    std::random_device rd{};
    auto mtgen = std::mt19937{ rd() };
    
    auto ud = std::uniform_int_distribution<>{1, 6};
    generate_and_print([&mtgen, &ud]() { return ud(mtgen); });
    std::cout << std::endl;
    
    auto nd = std::normal_distribution<>{ 5, 2 };
    generate_and_print([&mtgen, &nd]() { return static_cast<int>(std::round(nd(mtgen))); });
}
} // example_05


#include <iostream>
int main() {
    std::cout << "example_01 =>\r\n"; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 =>\r\n"; example_02::run(); std::cout << std::endl;
    std::cout << "example_03 =>\r\n"; example_03::run(); std::cout << std::endl;
    std::cout << "example_04 =>\r\n"; example_04::run(); std::cout << std::endl;
    std::cout << "example_05 =>\r\n"; example_05::run(); std::cout << std::endl;

    return 0;
}



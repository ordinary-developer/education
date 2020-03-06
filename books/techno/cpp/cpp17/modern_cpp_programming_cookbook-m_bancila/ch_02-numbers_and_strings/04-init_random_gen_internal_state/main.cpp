#include <random>
#include <array>
#include <algorithm>
#include <iostream>
namespace example_01 {
void run() {
    std::random_device rd{};
    
    std::array<int, std::mt19937::state_size> seed_data{};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    
    auto eng = std::mt19937{seq};
    
    auto dist = std::uniform_real_distribution<>{ 0, 1 };
    
    for (std::size_t i{0}; i < 10; ++i) 
        std::cout << dist(eng) << " ";
    std::cout << std::endl;
}
} // example 01

#include <iostream>
int main() {
    std::cout << "example_01 =>\r\n"; example_01::run(); std::cout << std::endl;

    return 0;
}



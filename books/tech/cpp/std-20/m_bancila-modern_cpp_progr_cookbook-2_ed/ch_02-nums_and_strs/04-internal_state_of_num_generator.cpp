#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <random>
namespace example_01 { // -> the "how to do it" section

void run() {
    std::random_device rd{};
    
    std::array<int, std::mt19937::state_size> seedData{};
    std::generate(std::begin(seedData), std::end(seedData), std::ref(rd));
    
    std::seed_seq seq(std::cbegin(seedData), std::cend(seedData));
    
    auto eng = std::mt19937{ seq };
    
    auto dist = std::uniform_real_distribution<>{ 0, 1 };
    
    for (int i{0}; i < 10; ++i)
        std::cout << dist(eng) << " ";
    std::cout << std::endl;
}
    
} // exampel_01


#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <random>
#include <cmath>
namespace example_02 { // -> an auxiliary example

void monte_carlo_simulation() {
    std::array<int, std::mt19937::state_size> seedData{};
    std::random_device rd{};
    
    std::generate(std::begin(seedData), std::end(seedData), std::ref(rd));
    std::seed_seq seq(std::cbegin(seedData), std::cend(seedData));
    auto eng = std::mt19937{ seq };
    auto dist = std::uniform_real_distribution<>{ 0, 1 };
    
    auto const Simulations = 100;
    auto const Samples = 50000;
    
    for (int j = 0; j < Simulations; ++j) {
        auto hit = 0;
        auto x = .0;
        auto y = .0;
        
        for (auto i = 0; i < Samples; ++i) {
            x = dist(eng);
            y = dist(eng);
            
            if (y <= std::sqrt(1 - std::pow(x, 2)))
                hit += 1;
        }
        
       std::cout << "" << 4.0 * hit / Samples << " ";
    }
    std::cout << std::endl;
}

void run() {
    monte_carlo_simulation();        
}
    
} // example_02


#include <iostream>
int main() {
    std::cout << "example_01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "example_02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl << std::endl;
    
	return 0;
}

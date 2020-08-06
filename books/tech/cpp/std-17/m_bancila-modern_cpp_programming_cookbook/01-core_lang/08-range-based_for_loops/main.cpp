// region [gettying ready]
#include <vector>
#include <map>
std::vector<int> getRates() {
    return std::vector<int>{ 1, 1, 2, 3, 5, 8, 13 };
}

std::multimap<int, bool> getRates2() {
    return std::multimap<int, bool> {
        { 1, true },
        { 1, true },
        { 2, false },
        { 3, true },
        { 5, true },
        { 8, false },
        { 13, true }
    };
}
// endregion [getting ready]

// region [how to do it]
#include <iostream>
namespace example_01 {
    
void run() {
    auto rates = getRates();
    for (int rate : rates)
        std::cout << rate << std::endl;
    
    for (int & rate : rates)
        rate *= 2;
}
} // example_01

#include <iostream>
namespace example_02 {
    
void run() {
    for (auto&& rate : getRates())
        std::cout << rate << std::endl;
    
    auto rates = getRates();
    for (auto & rate : rates)
        rate *= 2;
    
    for (auto const& rate : rates)
        std::cout << rate << std::endl;
}    
} // example_02

#include <iostream>
namespace example_03 {

void run() {
    for (auto&& [rate, flag] : getRates2())
        std::cout << rate << "-" << flag << std::endl;
} 
} // example_03
// endregion [how to do it]

#include <iostream>
int main() {
    getRates();
    getRates2();
    
    example_01::run();
    example_02::run();
    example_03::run();
    
    std::cout << "DONE" << std::endl;
    
    return 0;
}
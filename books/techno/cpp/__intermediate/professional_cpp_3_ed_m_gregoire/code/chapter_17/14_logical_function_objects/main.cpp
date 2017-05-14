#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <functional>


bool allTrue(const std::vector<bool>& flags) {
    return accumulate(begin(flags), end(flags), true, std::logical_and<>());
}

bool anyTrue(const std::vector<bool>& flags) {
    return accumulate(begin(flags), end(flags), false, std::logical_or<>());
}

auto main() -> int {
    std::vector<bool> myVector;
    int number;
    while (true) {
        std::cout << "Enter a value 0 or 1 to add (-1 to stop): ";
        std::cin >> number;
        if (-1 == number) {
            break;
        }
        myVector.push_back(1 == number);
    }

    std::cout << "allTrue? " << (allTrue(myVector) ? "yes" : "no") 
              << std::endl;
    std::cout << "anyTrue? " << (anyTrue(myVector) ? "yes" : "no")
              << std::endl;

    return 0;
}


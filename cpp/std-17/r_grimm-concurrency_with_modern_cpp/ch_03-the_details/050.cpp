#include <algorithm>
#include <execution>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
    std::cout << std::endl;

    std::vector<int> myVec{ 1, 2, 3, 4, 5 };

    try {
        std::for_each(std::begin(myVec), std::end(myVec),
            [](int) { throw std::runtime_error{ "Without execution policy" }; });
    }
    catch (const std::runtime_error & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::for_each(std::execution::seq, std::begin(myVec), std::end(myVec),
            [](int) { throw std::runtime_error{ "With execution policy" }; });
    }
    catch (const std::runtime_error & e) {
        std::cout << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Catch-all exceptions" << std::endl;
    }
}

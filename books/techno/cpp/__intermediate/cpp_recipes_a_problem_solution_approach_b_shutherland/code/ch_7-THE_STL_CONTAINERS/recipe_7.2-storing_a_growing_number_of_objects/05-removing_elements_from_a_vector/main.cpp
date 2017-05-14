#include <iostream>
#include <cstdint>
#include <vector>

int main() {
    std::vector<int32_t> stlVector
    {
        1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16
    };

    std::cout << "The size is: " << stlVector.size() << std::endl;
    std::cout << "The capacity is: " << stlVector.capacity()
              << std::endl << std::endl;

    for (auto&& number : stlVector)
        std::cout << number << ", ";
    std::cout << std::endl;


    while (stlVector.size() > 0) {
        auto iterator = stlVector.end() - 1;
        stlVector.erase(iterator);
    }

    std::cout << "The size is: " << stlVector.size() << std::endl;
    std::cout << "The capacity is: " << stlVector.capacity()
              << std::endl << std::endl;

    for (auto&& number : stlVector)
        std::cout << number << ", ";
    std::cout << std::endl;

    return 0;
}

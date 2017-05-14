#include <iostream>
#include <cstdint>

int main() {
    const uint32_t numberOfElements{ 5 };
    int32_t normalArray[numberOfElements]{ 10, 65, 3000, 2, 49 };

    for (uint32_t i{ 0 }; i < numberOfElements; ++i) 
        std::cout << normalArray[i] << std::endl;

    for (auto&& number : normalArray)
        std::cout << number << std::endl;

    return 0;
}

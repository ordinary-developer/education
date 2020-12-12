#include <iostream>
#include <cstdint>
#include <array>

int main() {
    const uint32_t numberOfElements{ 5 };
    std::array<int32_t, numberOfElements> stlArray{ 10, 53, 23 };

    for (uint32_t i{ 0 }; i < numberOfElements; ++i)
        std::cout << stlArray[i] << std::endl;

    for (auto&& number : stlArray)
        std::cout << number << std::endl;

    return 0;
}

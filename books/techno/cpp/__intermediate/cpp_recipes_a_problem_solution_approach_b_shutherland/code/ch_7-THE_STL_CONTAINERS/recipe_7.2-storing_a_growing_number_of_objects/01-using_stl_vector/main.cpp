#include <iostream>
#include <cstdint>
#include <vector>

int main() {
    std::vector<int32_t> stlVector{ 10, 65, 3000, 2, 4 };

    for (uint32_t i{ 0 }; i < stlVector.size(); ++i)
        std::cout << stlVector[i] << std::endl;

    for (auto&& number : stlVector)
        std::cout << number << std::endl;

    return 0;
}

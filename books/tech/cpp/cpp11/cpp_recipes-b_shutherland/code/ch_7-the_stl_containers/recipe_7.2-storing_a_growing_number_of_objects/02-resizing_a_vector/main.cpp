#include <iostream>
#include <cstdint>
#include <vector>

int main() {
    std::vector<int32_t> stlVector{ 10, 65, 3000, 2, 4 };
    std::cout << "The size is: " << stlVector.size() << std::endl;

    stlVector.emplace_back(50);
    std::cout << "The size is: " << stlVector.size() << std::endl;

    for (auto&& number : stlVector)
        std::cout << number << std::endl;

    return 0;
}

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>

using MyArray = std::array<uint32_t, 5>;

int main() {
    MyArray myArray{ 1, 2, 3, 4, 5 };

    std::for_each(myArray.cbegin(),
                  myArray.cend(),
                  [](auto&& number) {
                    std::cout << number << std::endl;
                  });

    return 0;
}

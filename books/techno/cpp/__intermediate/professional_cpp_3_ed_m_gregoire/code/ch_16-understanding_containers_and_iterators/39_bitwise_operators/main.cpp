#include <iostream>
#include <bitset>


auto main() -> int {
    auto str1 = "0011001100";
    auto str2 = "0000111100";
    std::bitset<10> bitsOne(str1);
    std::bitset<10> bitsTwo(str2);

    auto bitsThree = bitsOne & bitsTwo;
    std::cout << bitsThree << std::endl;
    bitsThree <<= 4;
    std::cout << bitsThree << std::endl;

    return 0;
}

#include <iostream>
#include <cstdint>

int main() {
    uint32_t leftBits{ 0x00011000 };
    uint32_t rightBits{ 0x00010100 };
    std::cout << std::showbase << std::hex;
    std::cout << "Resul of 0x00011000 | 0x00010100: "
              << (leftBits | rightBits) << std::endl;
    std::cout << "Result of 0x00011000 & 0x11100111: "
              << (leftBits | ~rightBits) << std::endl;

    return 0;
}

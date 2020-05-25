#include <iostream>
#include <cstdint>

int main() {
    uint32_t bits{ 0x00011000 };
    std::cout << bits << std::endl;
    std::cout << std::showbase << std::hex;
    std::cout << "Result of 0x00011000 & 0x00011000: "
              << (bits & bits) << std::endl;
    std::cout << "Result of 0x00011000 & 0x11100111: "
              << (bits & ~bits) << std::endl;

    return 0;
}

#include <iostream>
#include <cstdint>

int main() {
    const uint32_t maskBits{ 16 };
    uint32_t leftShifted{ 0x00001010 << maskBits };
    std::cout << std::showbase << std::hex;
    std::cout << "Left shifted: " << leftShifted << std::endl;

    return 0;
}

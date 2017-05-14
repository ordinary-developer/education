#include <iostream>
#include <cstdint>

int main() {
    const uint32_t maskBits{ 16 };
    int32_t leftShifted{ 0x00008080 << maskBits };
    std::cout << std::showbase << std::hex;
    std::cout << "Left shifted: " << leftShifted << std::endl;

    int32_t lowerMask{ 0x0000FFFF };
    leftShifted |= (0x11110110 & lowerMask);
    std::cout << "Packed left shifted: " << leftShifted << std::endl;

    int32_t rightShifted{ (leftShifted >> maskBits) };
    std::cout << "Right shifted: " << rightShifted << std::endl;
    std::cout << "Unmasked right shifted: " 
              << (rightShifted & lowerMask) << std::endl;

    return 0;
}

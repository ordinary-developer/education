#include <iostream>
#include <cstdint>

int main() {
    const uint32_t maskBits{ 16 };
    uint32_t leftShifted{ 0x00001010 << maskBits };
    std::cout << std::showbase << std::hex;
    std::cout << "Left shifted: " << leftShifted << std::endl;

    uint32_t lowerMask{ 0x0000FFFF };
    leftShifted |= (0x11110110 & lowerMask);
    std::cout << "Packed left shifted: " << leftShifted << std::endl;

    uint32_t lowerValue{ (leftShifted & lowerMask) };
    std::cout << "Lower value unmasked: " << lowerValue << std::endl;

    uint32_t upperValue{ (leftShifted >> maskBits) };
    std::cout << "Upper value unmasked: " << upperValue << std::endl;

    return 0;
}

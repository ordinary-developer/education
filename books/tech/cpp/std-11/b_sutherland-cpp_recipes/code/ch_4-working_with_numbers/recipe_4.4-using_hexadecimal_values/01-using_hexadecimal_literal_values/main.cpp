#include <iostream>
#include <cstdint>

int main() {
    uint32_t hexValue{ 0x89 };
    std::cout << "Decimal: " << hexValue << std::endl;
    std::cout << std::hex << "Hexadecimal: " << hexValue << std::endl;
    std::cout << std::showbase << std::hex 
              << "Hexadecimal (with base): "
              << hexValue << std::endl;

    return 0;
}


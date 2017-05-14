#include <iostream>
#include <cstdint>

int main() {
    const uint32_t maskBits{ 16 };
    uint32_t narrowingBits{ 0x00008000 << maskBits };

    std::cout << narrowingBits << std::endl;

    return 0;
}

#include <iostream>


void rawPutChar(const char* data, int charIndex) {
    std::cout.put(data[charIndex]);
}

auto main() -> int {
    const char* myStr = "hello";
    rawPutChar(myStr, 1);

    return 0;
}

#include <iostream>
#include <string>

const int kBufferSize = 1024;

auto main() -> int {
    char buffer[kBufferSize];
    std::cin.getline(buffer, kBufferSize);
    std::cout << "***" << buffer << "***" << std::endl;

    std::string myString;
    std::getline(std::cin, myString);
    std::cout << "***" << myString << "***" << std::endl;

    return 0;
}


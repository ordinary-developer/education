#include <iostream>
#include <stdexcept>

int SafeDivide(int num, int den) {
    if (0 == den) {
        throw std::invalid_argument("Divide by zero");
    }
    return num / den;
}

auto main() -> int {
    try {
        std::cout << SafeDivide(5, 2) << std::endl;
        std::cout << SafeDivide(10, 0) << std::endl;
        std::cout << SafeDivide(3, 3) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

#include <iostream>

#define SQUARE(x) (x * x)

auto main() -> int {
    // here 11 will be, not 25
    std::cout << SQUARE(2 + 3) << std::endl;

    return 0;
}


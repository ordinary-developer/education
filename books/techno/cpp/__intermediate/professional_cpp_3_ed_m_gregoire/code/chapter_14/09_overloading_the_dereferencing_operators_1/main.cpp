#include "Pointer.hpp"
#include <iostream>

auto main() -> int {
    Pointer<int> smartInt(new int);
    *smartInt = 5;
    std::cout << *smartInt << std::endl;

    return 0;
}

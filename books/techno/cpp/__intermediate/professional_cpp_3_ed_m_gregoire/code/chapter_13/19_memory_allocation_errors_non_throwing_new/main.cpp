#include <cstddef>
#include <iostream>
#include <limits>


auto main() -> int {
    int* ptr;
    size_t numInts = std::numeric_limits<int>::max();

    ptr = new(std::nothrow) int[numInts];
    if (nullptr == ptr) {
        std::cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory!" << std::endl;
        return 1;
    }

    return 0;
}

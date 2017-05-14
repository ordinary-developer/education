#include <cstddef>
#include <iostream>
#include <limits>


auto main() -> int {
    int* ptr;
    size_t numInts = std::numeric_limits<int>::max();

    try {
        ptr = new int[numInts];
    }
    catch (const std::bad_alloc& e) {
        std::cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory: "
                  << e.what() << std::endl;
        return 1;
    }

    return 0;
}

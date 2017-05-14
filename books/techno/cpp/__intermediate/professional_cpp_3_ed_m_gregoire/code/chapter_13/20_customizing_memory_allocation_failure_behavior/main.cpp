#include <cstddef>
#include <new>
#include <cstdlib>
#include <iostream>
#include <limits>


class PleaseTerminateMe : public std::bad_alloc { };

void myNewHandler() {
    std::cerr << "Unable to allocate memory." << std::endl;
    throw PleaseTerminateMe();
}

auto main() -> int {
    try {
        std::new_handler oldHandler = std::set_new_handler(myNewHandler);
        size_t numInts = std::numeric_limits<int>::max();
        int* ptr = new int[numInts];

        std::set_new_handler(oldHandler);
    }
    catch (const PleaseTerminateMe& e) {
        std::cerr << __FILE__ << "(" << __LINE__
                  << "): Terminating program." << std::endl;
        return 1;
    }

    return 0;
}

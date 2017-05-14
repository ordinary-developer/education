#include "Array.hpp"

#include <iostream>


auto main() -> int {
    Array<int> myArray;
    for (size_t i = 0; i < 10; i++) {
        myArray[i] = 100;
    }

    for (size_t i = 0; i < 10; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

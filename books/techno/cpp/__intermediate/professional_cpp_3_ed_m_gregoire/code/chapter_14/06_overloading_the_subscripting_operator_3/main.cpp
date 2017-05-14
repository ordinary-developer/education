#include "Array.hpp"

#include <iostream>


void printArray(const Array<int>& arr, size_t size);

auto main() -> int {
    Array<int> myArray;
    for (size_t i = 0; i < 10; i++) {
        myArray[i] = 100;
    }

    printArray(myArray, 10);

    return 0;
}

void printArray(const Array<int>& arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

namespace example1 {
void run() {
    int myIntArray[10];
    int* myIntPtr = myIntArray;
    myIntPtr[4] = 5;
}
}

#include <cstddef>
namespace example2 {
void doubleInts1(int* theArray, size_t inSize) {
    for (size_t i{0}; i < inSize; ++i)
        theArray[i] *= 2;
}

void doubleInts2(int theArray[], size_t inSize) {
    for (size_t i{0}; i < inSize; ++i)
        theArray[i] *= 2;
}

void doubleInts3(int theArray[2], size_t inSize) {
    for (size_t i{0}; i < inSize; ++i)
        theArray[i] *= 2;
}

void run() {
    size_t arraySize{4};
    int* heapArray{ new int[arraySize] { 1, 5, 3, 4 } };
    doubleInts1(heapArray, arraySize);
    doubleInts2(heapArray, arraySize);
    doubleInts3(heapArray, arraySize);
    delete [] heapArray;
    heapArray = nullptr;

    int stackArray[]{ 5, 7, 9, 11 };
    arraySize = sizeof(stackArray) / sizeof(stackArray[0]);
    doubleInts1(stackArray, arraySize);
    doubleInts1(&stackArray[0], arraySize);
    doubleInts2(stackArray, arraySize);
    doubleInts2(&stackArray[0], arraySize);
    doubleInts3(stackArray, arraySize);
    doubleInts3(&stackArray[0], arraySize);
}
}

#include <cstddef>
#include <iostream>
namespace example3 {
template <size_t N> 
void doubleIntsStack(int (&theArray)[N]) {
    for (size_t i{0}; i < N; ++i)
        theArray[i] *= 2;
}

void run() {
    int const arraySize = 5;
    int stackArray[arraySize]{1, 2, 3, 4, 5};

    std::cout << "before duplicating ..." << std::endl;
    for (auto const& element : stackArray)
        std::cout << element << std::endl;

    doubleIntsStack<arraySize>(stackArray);

    std::cout << "after duplicating ..." << std::endl;
    for (auto const& element : stackArray)
        std::cout << element << std::endl;

}
}

int main() {
    example1::run();
    example2::run();
    example3::run();

    return 0;
}

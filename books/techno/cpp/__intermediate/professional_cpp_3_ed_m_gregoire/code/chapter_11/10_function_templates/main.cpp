#include "SpreadsheetCell.hpp"

#include <cstddef>
#include <iostream>
#include <cstring>


static const size_t NOT_FOUND = (size_t)(-1);
template <typename T>
size_t Find(T& value, T* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return NOT_FOUND;
}
template <typename T, size_t S>
size_t Find(T& value, T(&arr)[S]) {
    return Find(value, arr, S);
}

template<>
size_t Find<const char*>(const char*& value, const char** arr, size_t size) {
    std::cout << "Specialization" << std::endl;
    for (size_t i = 0; i < size; i++) {
        if (strcmp(arr[i], value) == 0) {
            return i;
        }
    }
    return NOT_FOUND;
}

auto main() -> int {
    int x = 3;
    int intArr[] = {1, 2, 3, 4};
    size_t sizeIntArr = sizeof(intArr) / sizeof(int);
    size_t res;
    res = Find(x, intArr, sizeIntArr);
    res = Find<int>(x, intArr, sizeIntArr);
    if (res != NOT_FOUND) {
        std::cout << res << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }

    double d1 = 5.6;
    double dArr[] = {1.2, 3.4, 5.7, 7.5};
    size_t sizeDoubleArr = sizeof(dArr) / sizeof(double);
    res = Find(d1, dArr, sizeDoubleArr);
    res = Find<double>(d1, dArr, sizeDoubleArr);
    if (res != NOT_FOUND) {
        std::cout << res << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }

    // will not be compiled
    // res = Find(x, dArr, sizeDoubleArr);
    
    SpreadsheetCell c1(10);
    SpreadsheetCell c2Arr[2] = 
        {SpreadsheetCell(4), SpreadsheetCell(10)};
    size_t sizeC2Arr = sizeof(c2Arr) / sizeof(SpreadsheetCell);
    res = Find(c1, c2Arr, sizeC2Arr);
    res = Find<SpreadsheetCell>(c1, c2Arr, sizeC2Arr);

    int x2 = 3, intArr2[] = {1, 2, 3, 4};
    size_t res2 = Find(x2, intArr2);

    const char* word = "two";
    const char* arr[] = {"one", "two", "three", "four"};
    size_t sizeArr = sizeof(arr) / sizeof(arr[0]);
    res = Find<const char*>(word, arr, sizeArr);
    res = Find(word, arr, sizeArr);

    return 0;
}

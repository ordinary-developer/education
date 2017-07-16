#include "spreadsheet_cell.hpp"

#include <cstddef>
#include <iostream>
#include <cstring>

static const size_t NOT_FOUND = (size_t)(-1);

template <typename T>
size_t Find(const T& value, const T* values, const size_t size) {
    std::cout << "Find(const T&, const T*, const size_t)" << std::endl;

    for (size_t i{0}; i < size; ++i)
        if (values[i] == value)
            return i;

    return NOT_FOUND;
}
template <typename T>
size_t Find(T* const& value, T** const values, const size_t size) {
    std::cout << "Find(T* const&, T** const, const size)" << std::endl;

    for (size_t i{0}; i < size; ++i)
        if (*values[i] == *value)
            return i;

    return  NOT_FOUND;
}

size_t Find(const char*& value, 
            const char** values, 
            size_t size)
{
    std::cout << "Find(const char*&, const char**, size_t)" << std::endl;

    for (size_t i{0}; i < size; ++i) 
        if (0 == strcmp(values[i], value))
            return i;

    return NOT_FOUND;
}


int main() {
    size_t res{ NOT_FOUND };

    // #region example 1
    int x = 3, intArr[] = { 1, 2, 3, 4 };
    size_t sizeArr{ sizeof(intArr) / sizeof(int) };
    res = Find(x, intArr, sizeArr);
    res = Find<int>(x, intArr, sizeArr);

    int *px = &x, *pArr[] = { &x, &x };
    sizeArr = sizeof(pArr) / sizeof(pArr[0]);
    res = Find(px, pArr, sizeArr);
    std::cout << "----------" << std::endl;
    // #end region example 1
    
    // #region example 2
    double d1 = 5.6, dArr[] = { 1.2, 3.4, 5.7, 7.5 };
    sizeArr = sizeof(dArr) / sizeof(double);
    res = Find(d1, dArr, sizeArr);
    res = Find<double>(d1, dArr, sizeArr);
    std::cout << "----------" << std::endl;
    // #end region example 2
    
    // #region example 3
    const char* word = "two";
    const char* arr[] = { "one", "two", "three", "four" };
    sizeArr = sizeof(arr) / sizeof(arr[0]);
    res = Find<const char*>(word, arr, sizeArr);
    res = Find(word, arr, sizeArr);
    std::cout << "----------" << std::endl;
    // #end region example 3
    
    // #region example 4
    SpreadsheetCell c1{10}, c2[] = { SpreadsheetCell{4}, 
                                     SpreadsheetCell{10} };
    sizeArr = sizeof(c2) / sizeof(c2[0]);
    res = Find(c1, c2, sizeArr);
    res = Find<SpreadsheetCell>(c1, c2, sizeArr);

    SpreadsheetCell *pc1 = &c1;
    SpreadsheetCell *psa[] = { &c1, &c1 };
    sizeArr = sizeof(psa) / sizeof(psa[0]);
    res = Find(pc1, psa, sizeArr);
    // #end region example 4

    return 0;
}


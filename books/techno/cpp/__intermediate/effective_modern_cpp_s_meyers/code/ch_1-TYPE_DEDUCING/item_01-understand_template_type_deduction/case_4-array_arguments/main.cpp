// template <typename T>
// void f(ParamType parameter);
//
// f(expr)



#include <iostream>
#include <cstddef>
#include <array>

using namespace std;

template <typename T>
void f1(T parameter) {
    cout << parameter << endl;
}

template <typename T>
void f2(T& parameter) {
    cout << parameter << endl;
}

template <typename T, size_t N>
constexpr size_t arraySize(T(&)[N]) noexcept
{
    return N;
}

int main()
{
    const char name[] = "J. P. Briggs";
    const char* ptr = name;

    // "T" is "const char*"
    // "ParamType" is "const char*"
    f1(name);

    // "T" is "const char[13]" (yeee...)
    // "ParamType" is "const char (&)[13]"
    f2(name);

    int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };
    int mappedVals[arraySize(keyVals)];
    
    std::array<int, arraySize(keyVals)> mappedValues;
  
    return 0;
}
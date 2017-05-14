#include <iostream>
using namespace std;

// template <typename T>
// void f(ParamType parameter);
//
// f(expr)

template <typename T>
void func_for_x(T parameter) { } 

template <typename T>
void func_for_cx(const T parameter) { }

template <typename T>
void func_for_rx(const T& parameter) { } 

void someFunc(int a, double b) {
    
}


int main()
{
    const char name[] = "R. N. Briggs";
    
    // arr1's type is "const char*"
    auto arr1 = name;
    // arr2's type is "const char (&)[13]
    auto& arr2 = name;
    
    // func1's type is "void (*)(int, double)
    auto func1 = someFunc;
    // func2's type is "void (&)(int, double)
    auto& func2 = someFunc;
    
    return 0;
}
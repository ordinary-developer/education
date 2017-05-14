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

int main()
{
    int x = 27;
    const int cx = x;
    const auto& rx = x;
    
    
    // the next strings are the same in a type deducing context
    // "x" is "int" and lvalue
    // "T" is "int&", "ParamType" is "int&", "uref1" is "int&"
    auto&& uref1 = x;
    func_for_x(uref1);

    // the next strings are the same in a type deducing context
    // "cx" is "const int" and lvalue
    // "T" is "const int&", "ParamType" is "const int&", "uref2" is "const int&"
    auto&& uref2 = cx;
    func_for_cx(uref2);
    
    // the next strings are the same in a type deducing context
    // "27" is "int" and rvalue
    // "T" is "int&&", "ParamType" is "int&&"
    auto&& uref3 = 27;
    func_for_rx(uref3);
    
    return 0;
}
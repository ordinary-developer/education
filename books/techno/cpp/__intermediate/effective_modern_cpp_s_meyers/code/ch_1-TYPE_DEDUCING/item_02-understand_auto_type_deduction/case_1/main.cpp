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
    // the next strings are the same in a type deducing context
    // "T" is "int", "ParamType" is "int", "x" is "int"
    auto x = 27;
    func_for_x(x);

    // the next strings are the same in a type deducing context
    // "T" is "int", "ParamType" is "const int", "cx" is "const int"
    const auto cx = x;
    func_for_cx(cx);

    // the next strings are the same in a type deducing context
    // "T" is "int", "ParamType" is "const int&", "rx" is "const int&"
    const auto& rx = x;
    func_for_rx(rx);
    
    return 0;
}
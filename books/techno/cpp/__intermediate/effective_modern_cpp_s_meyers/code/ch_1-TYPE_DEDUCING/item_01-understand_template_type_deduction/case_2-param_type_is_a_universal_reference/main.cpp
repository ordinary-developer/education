// template <typename T>
// void f(ParamType parameter);
//
// f(expr)


// ParamType is a universal reference

// Type deduction works like this:
// 1. If expr is an lvalue, both T and ParamType are deduced to be lvalue references.
//    That's doubly unusual. 
//    First, it's the only situation in template type deduction
//    where T is deduced to be a reference.
//    Second, although ParamType is declared 
//    using the syntax for an rvalue reference,
//    its deduced type is an lvalue reference
// 2. If expr is an rvalue, the "normal" (i.e. Case1) ruless apply.

#include <iostream>
using namespace std;

template <typename T>
void f(T&& parameter) {
    cout << parameter << endl;
}

int main()
{
    int x = 27;
    const int cx = x;
    const int& rx = x;

    // x is an lvalue
    // "T" is "int&"
    // "ParamType" is "int&"
    f(x);
  
    // cx in an lvalue
    // "T" is "const int&"
    // "ParamType" is "const int&"
    f(cx);

    // rx is an lvalue
    // "T" is "const int&"
    // "ParamType" is "const int&"
    f(rx);

    // 27 is an rvalue
    // "T" is "int"
    // "ParamType" is "int&&"
    f(27);
    return 0;
}
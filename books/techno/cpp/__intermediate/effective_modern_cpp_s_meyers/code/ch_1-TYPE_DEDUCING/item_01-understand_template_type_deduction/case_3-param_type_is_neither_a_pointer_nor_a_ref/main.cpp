// template <typename T>
// void f(ParamType parameter);
//
// f(expr)


// ParamType is neither a pointer nor a reference
// (so we are dealing with pass-by-value:
//
// Type deduction works like this:
// 1. If expr's type is a reference, ignore the reference part.
// 2. If, after ignoring expr's reference-ness, expr is const, ignore that too.
//    If it's volatile, also ignore that.

#include <iostream>
using namespace std;

template <typename T>
void f(T parameter) {
    cout << parameter << endl;
}

int main()
{
    int x = 27;
    const int cx = x;
    const int& rx = x;

    // "T" is "int"
    // "ParamType" is "int"
    f(x);

    // "T" is "int"
    // "ParamType" is "int"
    f(cx);

    // "T" is "int"
    // "ParamType" is "int"
    f(rx);


    // "T" is "const char*" (?)
    // "ParamType" is const char*
    const char* const ptr = "Fun with pointers";
    f(ptr);
  
    return 0;
}

// template <typename T>
// void f(ParamType parameter);
//
// f(expr)


// ParamType is a reference or a pointer type,
// but not a universal reference

// Type deduction works like this:
// 1. If expr's type is a reference, ignore the reference part.
// 2. Then pattern-math expr's type against ParamType to determine T.

#include <iostream>
using namespace std;

template <typename T>
void f(const T& parameter) {
    cout << parameter << endl;
}

int main()
{
    int x = 27;
    const int cx = x;
    const int& rx = x;
    
    // T is "int", ParamType is "const int&"
    f(x);
    
    // T is "int", ParamType is "const int&"
    f(cx);
    
    // T is "int", ParamType is "const int&"
    f(rx);
  
    return 0;
}
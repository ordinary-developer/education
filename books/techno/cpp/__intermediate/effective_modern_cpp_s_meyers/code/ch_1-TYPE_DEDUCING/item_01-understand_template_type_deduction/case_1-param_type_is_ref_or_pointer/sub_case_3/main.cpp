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
void f(T* parameter) {
    cout << *parameter << endl;
}

int main()
{
    int x = 27;
    const int* px = &x;    
    
    // T is "int", ParamType is "int*"
    f(&x);
    
    // T is "const int", ParamType is "const int*"
    f(px); 
  
    return 0;
}
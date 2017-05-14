#include <iostream>

using namespace std;

// template <typename T>
// void f(ParamType parameter);
//
// f(expr)

template <typename T>
void f(const T& parameter) {
    cout << parameter << endl;
}


int main()
{
   // T is deduced to be int
   // ParamType is deduced to be const int
   int x = 0;
   f(x);
  
   return 0;
}


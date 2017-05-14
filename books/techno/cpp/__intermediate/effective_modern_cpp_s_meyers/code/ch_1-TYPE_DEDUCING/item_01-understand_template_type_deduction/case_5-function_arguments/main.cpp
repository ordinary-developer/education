// template <typename T>
// void f(ParamType parameter);
//
// f(expr)



#include <iostream>
using namespace std;

void someFunc(int a, double b) {
    cout << a << endl;
    cout << b << endl;
}

template <typename T>
void f1(T parameter) {
    parameter(1, 2);
}

template <typename T>
void f2(T& parameter) {
    parameter(1, 2);
}

int main()
{
    // "T" is "void (*)(int, double)" ???
    // "ParamType" is "void (*)(int, double)"
    f1(someFunc);

    // "T" is "void (int, double)" (???)
    // "ParamType" is "void(&)(int, double)"
    f2(someFunc);
  
    return 0;
}
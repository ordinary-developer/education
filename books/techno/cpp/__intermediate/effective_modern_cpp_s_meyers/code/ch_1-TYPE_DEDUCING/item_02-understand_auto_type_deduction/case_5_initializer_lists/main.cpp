#include <iostream>
using namespace std;

// "Auto" type deduction assumes 
// that a braced initializer represents a "std::initializer_list"
// and template type deduction doesn't

// template with parameter declaration
// equivalent to x's declaration
template <typename T>
void f1(T parameter) { }

template <typename T>
void f2(std::initializer_list<T> initList) { }

int main()
{
    // x's type is std::initializer_list<int>"
    auto x = { 11, 23, 9 };
    // the next string will not be compiled
    //f1({ 11, 23, 9 });
    
    // here, T is deduced as "int",
    // and initList's type is std::initializer_list<int>
    f2({ 11, 23, 9});
 
    return 0;
}
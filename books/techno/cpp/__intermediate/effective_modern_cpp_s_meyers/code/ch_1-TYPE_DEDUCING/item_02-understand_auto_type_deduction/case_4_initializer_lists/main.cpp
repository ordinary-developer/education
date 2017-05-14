#include <iostream>
using namespace std;

// "Auto" type deduction assumes 
// that a braced initializer represents a "std::initializer_list"
// and template type deduction doesn't
int main()
{
    // C++98 
    int x01 = 27;
    int x02(27);
    // C++11
    int x03 = { 27 };
    int x04{ 27 };
    
    // type is "int", value is "27"
    auto x1 = 27;
    // type is "int", value is "27"
    auto x2(27);
    // type is "std::initializer_list<int>", value is "{ 27 }"
    auto x3 = { 27 };
    // type is "std::initializer_list<int>", value is "{ 27 }"
    auto x4{ 27 };
    
    // the next string will give an error
    // can't deduce T for std::initializer_list<T>
    //auto x5 = { 1, 2, 3.0 };
    
    return 0;
}
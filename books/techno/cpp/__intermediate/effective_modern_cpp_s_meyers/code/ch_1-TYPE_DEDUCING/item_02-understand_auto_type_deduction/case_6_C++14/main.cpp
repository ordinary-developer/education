#include <iostream>
#include <vector>
using namespace std;

// auto in a function return type or a lambda parameter
//implies template type deduction, not auto type deduction.

// here a compile error will be
/*
auto createInitList() 
{
    return { 1, 2, 3 };
}
*/

int main()
{   
    std::vector<int> v;
    auto resetV = [&v](const auto& newValue) { v = newValue; };
    // here a compile error will be
    //resetV({ 1, 2, 3 });
    
    return 0;
}
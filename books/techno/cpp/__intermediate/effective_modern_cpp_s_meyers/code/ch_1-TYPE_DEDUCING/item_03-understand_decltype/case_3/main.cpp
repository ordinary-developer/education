#include <iostream>
#include <deque>
using namespace std;

// "decltype(auto)" can be convenient for declaring variables
// when you want to apply the "decltype" type deduction rules
// to the initializing expression

class Widget { };

int main()
{
    Widget w;
    const Widget& cw = w;   
    
    // "auto" type deduction
    // myWidget1's type is "Widget"
    auto myWidget1 = cw;
    
    // "decltype" type deduction
    // myWidget2's type is "const Widget&"
    decltype(auto) myWidget2 = cw;
    
    return 0;
}
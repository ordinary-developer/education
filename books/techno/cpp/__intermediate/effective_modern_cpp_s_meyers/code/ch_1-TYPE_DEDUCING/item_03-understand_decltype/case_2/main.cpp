#include <iostream>
#include <deque>
using namespace std;

// For functions with an "auto" return type specification,
// compilers employ template type deduction.

// C++11 style
template <typename Container, typename Index>
auto authAndAccess1(Container& c, Index i)
 -> decltype(c[i])
{
    // doSomething();
    return c[i];
}

// C++14 style
template <typename Container, typename Index>
auto authAndAccess2(Container& c, Index i)
{
    // doSomething();
    return c[i];
}

// works only in C++14 (I don't remember if realy)
// "decltype(auto)":
// "auto" specifes that the type is to be deduced
// and "decltype" says that "decltype" rules should be used during the deduction
template <typename Container, typename Index>
decltype(auto)
authAndAccess3(Container& c, Index i)
{
    // doSomething();
    return c[i];
}

int main()
{
    std::deque<int> d;
    
    authAndAccess1(d, 5) = 10;
    // here a compile error will be
    // authAndAccess2(d, 5) = 10;
    authAndAccess3(d, 5) = 10;	    
    
    return 0;
}
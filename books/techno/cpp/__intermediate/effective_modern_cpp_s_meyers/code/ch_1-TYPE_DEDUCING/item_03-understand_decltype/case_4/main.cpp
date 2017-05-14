#include <iostream>
#include <deque>
#include <string>
using namespace std;

template <typename Container, typename Index>
decltype(auto) authAndAccess1(Container& c, Index i)
{
    // doSomething();
    return c[i];
}

// c is now a universal reference
template <typename Container, typename Index>
decltype(auto) authAndAccess2(Container&& c, Index i)
{
    // doSomething();
    return c[i];
}

// final C++14 version
template <typename Container, typename Index>
decltype(auto)
authAndAccess3(Container&& c, Index i)
{
    // doSomething();
    return std::forward<Container>(c)[i];
}

// final C++11 version
template <typename Container, typename Index>
auto
authAndAccess4(Container&& c, Index i)
-> decltype(std::forward<Container>(c)[i])
{
    // doSomething();
    return std::forward<Container>(c)[i]; 
}

std::deque<std::string> makeStringDeque() 
{
    std::deque<std::string> result;
    result.push_back("string");
    return result;
}

int main()
{
    // will not compile
    // auto s1 = authAndAccess1(makeStringDeque(), 0);
    
    auto s2 = authAndAccess2(makeStringDeque(), 0);
    
    auto s3 = authAndAccess3(makeStringDeque(), 0);
    
    auto s4 = authAndAccess4(makeStringDeque(), 0);
    
    return 0;
}
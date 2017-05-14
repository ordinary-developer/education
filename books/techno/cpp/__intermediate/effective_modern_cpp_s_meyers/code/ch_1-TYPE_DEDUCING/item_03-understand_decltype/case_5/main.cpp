#include <iostream>
using namespace std;

// decltype(x) is "int",
// so f1 returns "int"
decltype(auto) f1()
{
    int x = 0;
    // ...
    return x;
}

// decltype((x)) is "int&",
// so f2 returns "int&"
decltype(auto) f2()
{
    int x = 0;
    // ...
    return (x);
}

int main()
{   
    // decltype(x) is "int"
    // decltype((x)) is "int&"
    int x = 0;
    
    
    return 0;
}
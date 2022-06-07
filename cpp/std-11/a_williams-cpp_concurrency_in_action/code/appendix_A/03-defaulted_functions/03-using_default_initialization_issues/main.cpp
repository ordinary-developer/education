#include <iostream>

struct X
{
    int a;
};

int main()
{
    X x1;
    std::cout << x1.a << std::endl; // here undefined behavior may be

    X x2{};
    std::cout << x2.a << std::endl; // default value

    X x3 = X();
    std::cout << x3.a << std::endl; // default value

    X x4 = X{};
    std::cout << x4.a << std::endl; // default value

    return 0;
}

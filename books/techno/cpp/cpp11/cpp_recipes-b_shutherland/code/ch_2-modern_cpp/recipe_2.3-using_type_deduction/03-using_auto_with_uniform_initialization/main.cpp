#include <iostream>
#include <typeinfo>


class MyClass { };

int main() {
    auto variable{ 1 };
    std::cout << "Type of variable: " << typeid(variable).name()
              << std::endl;

    auto variable2{ MyClass{ } };
    std::cout << "Type of variable: " << typeid(variable2).name()
              << std::endl;

    return 0;
}

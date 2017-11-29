#include <iostream>
#include <typeinfo>


class MyClass { };

int main() {
    auto variable = MyClass();
    std::cout << "Type of variable: " << typeid(variable).name()
              << std::endl;

    return 0;
}

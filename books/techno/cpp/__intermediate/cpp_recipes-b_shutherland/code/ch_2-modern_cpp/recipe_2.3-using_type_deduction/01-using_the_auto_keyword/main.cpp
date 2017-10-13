#include <iostream>
#include <typeinfo>


int main() {
    auto variable = 1;
    std::cout << "Type of variable: " << typeid(variable).name()
              << std::endl;

    return 0;
}

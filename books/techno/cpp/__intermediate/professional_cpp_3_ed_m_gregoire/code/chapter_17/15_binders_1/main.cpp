#include <iostream>
#include <string>
#include <functional>

void func(int number, const std::string& str) {
    std::cout << "func(" << number << ", " << str << ")" << std::endl;
}

void overloaded(int number) { 
    std::cout << "func(" <<number << ")" << std::endl;
}
void overloaded(float number) { 
    std::cout << "func(" <<number << ")" << std::endl;
}

auto main() -> int {
    std::string myString = "abc";
    auto f1 = bind(func, std::placeholders::_1, myString);
    f1(16);

    auto f2 = bind(func, std::placeholders::_2, std::placeholders::_1);
    f2("Test", 32);

    // auto f3 = std::bind(overloaded, std::placeholders::_1); // ERROR
    auto f4 = std::bind((void(*)(float))overloaded, std::placeholders::_1); 
    f4(1);

    return 0;
}

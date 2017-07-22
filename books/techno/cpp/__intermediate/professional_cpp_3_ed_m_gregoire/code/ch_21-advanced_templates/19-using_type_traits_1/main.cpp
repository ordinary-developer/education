#include <type_traits>
#include <iostream>

int main() {
    if (std::is_integral<int>::value) {
        std::cout << "int is integral<bool>" << std::endl;
    }
    else {
        std::cout << "int is not integral" << std::endl;
    }

    if (std::is_class<std::string>::value) {
        std::cout << "string is a class" << std::endl;
    }
    else {
        std::cout << "string is not a class" << std::endl;
    }

    return 0;
}

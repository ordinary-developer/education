#include <iostream>


int main() {
    int x{ 42 };

    std::cout << "x   = " << x   << "\n";
    std::cout << "++x = " << ++x << "\n";
    std::cout << "x   = " << x   << "\n";
    std::cout << "x++ = " << x++ << "\n";
    std::cout << "x   = " << x   << "\n";

    return 0;
}

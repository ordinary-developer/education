#include <iostream>

int main() {
    std::cout << '+';
    for (int i{ 0 }; i != 20; ++i)
        std::cout << '-';
    std::cout << "+\n|";

    for (int i{ 0 }; i != 3; ++i)
        std::cout << ' ';
    std::cout << "Hello, reader!";

    for (int i{ 0 }; i != 3; ++i)
        std::cout << ' ';
    std::cout << "|\n+";

    for (int i{ 0 }; i != 20; ++i)
        std::cout << '-';
    std::cout << "+\n";

    return 0;
}

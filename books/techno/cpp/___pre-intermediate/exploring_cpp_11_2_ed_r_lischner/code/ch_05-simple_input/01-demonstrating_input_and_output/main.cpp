#include <iostream>

int main() {
    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y;
    std::cin >> y;

    int z{ x + y };
    std::cout << "The sun of " << x << " and " << y << " is "
              << z << "\n";
}

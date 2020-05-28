#include <iostream>

int main() {
    int x;

    while (std::cin >> x) {
        if (0 == x % 2)
            std::cout << x << " is even.\n";
        else
            std::cout << x << " is odd.\n";
    }
}

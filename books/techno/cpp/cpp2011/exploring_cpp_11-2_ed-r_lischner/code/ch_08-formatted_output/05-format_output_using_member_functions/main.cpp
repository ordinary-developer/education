#include <iostream>

int main() {
    std::cout.fill('0');
    std::cout.width(6);
    std::cout << 42 << '\n';

    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout.width(6);
    std::cout << 42 << '\n';

    std::cout.fill('-');
    std::cout.width(4);
    std::cout << -42 << '\n';

    return 0;
}

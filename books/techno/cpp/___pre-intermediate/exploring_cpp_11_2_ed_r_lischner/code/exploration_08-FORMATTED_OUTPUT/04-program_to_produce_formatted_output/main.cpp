#include <iomanip>
#include <iostream>


int main() {
    std::cout << std::setfill('0') << std::setw(6) << 42 << '\n';
    std::cout << std::left << std::setw(6) << 42 << '\n';
    std::cout << 42 << '\n';
    std::cout << std::setfill('-') << std::setw(4) << -42 << '\n';

    return 0;
}

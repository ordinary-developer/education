#include <iostream>
#include <iomanip>

int main() {
    float large_number = 123456.789;

    std::cout << std::scientific << large_number << '\n';
    std::cout << std::fixed << large_number << '\n';
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << large_number;

    return 0;
}

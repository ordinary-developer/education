#include <iostream>
#include <string>


int main() {
    std::string empty1;
    std::cout << "|" << empty1 << "|\n";

    std::string empty2{ };
    std::cout << "|" << empty2 << "|\n";

    return 0;
}

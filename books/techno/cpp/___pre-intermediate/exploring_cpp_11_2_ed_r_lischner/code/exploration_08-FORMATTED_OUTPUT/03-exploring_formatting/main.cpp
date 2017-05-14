#include <iomanip>
#include <iostream>

int main() {
    std::cout << '|' 
              << std::setfill('*') << std::setw(6) << 1234 
              << '|' << '\n';

    std::cout << '|' 
              << std::left << std::setw(6) << 1234 
              << '|' << '\n';

    std::cout << '|' 
              << std::setw(6) << -1234 
              << '|' << '\n';

    std::cout << '|' 
              << std::right << std::setw(6) << -1234 
              << '|' << '\n';

    return 0;
}


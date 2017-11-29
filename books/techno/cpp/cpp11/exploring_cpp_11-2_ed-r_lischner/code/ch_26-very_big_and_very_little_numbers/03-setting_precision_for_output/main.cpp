#include <iostream>
#include <iomanip>

int main() {
    double const pi{ 3.141592653589792 };
    std::cout.precision(12);
    std::cout << pi << '\n';
    std::cout << std::setprecision(4) << pi << '\n';

    return 0;
}

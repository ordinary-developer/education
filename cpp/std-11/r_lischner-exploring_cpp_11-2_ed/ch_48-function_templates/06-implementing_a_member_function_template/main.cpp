#include <iostream>

#include "rational.hpp"


int main() {
    rational r{ 42, 10 };
    double d{ r.convert<double>() };
    std::cout << d << std::endl;

    return 0;
}

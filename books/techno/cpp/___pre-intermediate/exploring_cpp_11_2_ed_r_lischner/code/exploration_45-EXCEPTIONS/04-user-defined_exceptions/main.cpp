#include <iostream>

#include "rational.hpp"


int main() {
    try {
        rational r{ 1, 0 };
    }
    catch(rational::zero_denominator const& ex) {
        std::cerr << "zeror denominator in rational number\n";
    }

    return 0;
}

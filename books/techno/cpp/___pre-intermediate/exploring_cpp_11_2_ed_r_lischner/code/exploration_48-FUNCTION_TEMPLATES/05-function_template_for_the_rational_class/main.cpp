#include <iostream>

#include "rational.hpp"

template <class T, class R>
T convert(R const& r) {
    return static_cast<T>(r.numerator()) / r.denominator();
}

int main() {
    rational r{ 42, 10 };
    double d{ convert<double>(r) };
    std::cout << d << std::endl;


    return 0;
}

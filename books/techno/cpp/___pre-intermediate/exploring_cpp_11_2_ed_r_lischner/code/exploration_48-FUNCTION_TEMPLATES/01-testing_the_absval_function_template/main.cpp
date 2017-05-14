#include <iostream>
#include "rational.hpp"


template<class T>
T absval(T x) {
    return (x < 0 ? -x : x);
}

int main() {
    std::cout << absval(-42) << '\n';
    std::cout << absval(-4.2) << '\n';
    std::cout << absval(42) << '\n';
    std::cout << absval(4.2) << '\n';
    std::cout << absval(-42L) << '\n';
    std::cout << absval(rational{ 42, 5 }) << '\n';
    std::cout << absval(rational{ -42, 5 }) << '\n';
    std::cout << absval(rational{ 42, -5 }) << '\n';

    return 0;
}

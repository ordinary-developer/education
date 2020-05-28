#include <cassert>
#include <cstdlib>
#include <iostream>


int gcd(int n, int m) {
    n = std::abs(n);
    while (m != 0) {
        int tmp{ n % m };
        n = m;
        m = tmp;
    }

    return n;
}

struct rational {
    void reduce() {
        assert(denominator != 0);
        int div{ gcd(numerator, denominator) };
        numerator = numerator / div;
        denominator = denominator / div;
    }

    int numerator;
    int denominator;
};


int main() {
    rational pi{};
    pi.numerator = 1420;
    pi.denominator = 452;
    pi.reduce();
    std::cout << "pi is approximately " << pi.numerator << "/"
              << pi.denominator << '\n';

    return 0;
}

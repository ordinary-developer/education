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
    rational(int num, int den) 
        : numerator{ num }, denominator{ den }
    {
        reduce();
    }

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
    rational pi{ 1420, 452 };
    std::cout << "pi is approximately " << pi.numerator << "/"
              << pi.denominator << '\n';    
    return 0;
}

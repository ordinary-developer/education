#include <cstdlib>
#include <cassert>
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>


int gcd(int n, int m) {
    n = std::abs(n);
    while (0 != m) {
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

    rational(int num) 
        : numerator{ num }, denominator{ 1 } { }

    rational(double r) 
        : rational{ static_cast<int>(r * 10000), 1000 } { }


    void assign(int num, int den) {
        numerator = num;
        denominator = den;
        reduce();
    }

    void reduce() {
        assert(0 != denominator);
        if (denominator < 0) {
            denominator = - denominator;
            numerator = - numerator;
        }
        int div{ gcd(numerator, denominator) };
        numerator = numerator / div;
        denominator = denominator / div;
    }

    int numerator;
    int denominator;
};

std::ostream& operator<<(std::ostream& out, rational const& rat) {
    std::ostringstream tmp{};
    tmp << rat.numerator;
    if (1 != rat.denominator)
        tmp << '/' << rat.denominator;
    out << tmp.str();

    return out;
}

int main() {
    rational r{ 1, 2 };
    std::cout << r << std::endl;

    return 0;
}

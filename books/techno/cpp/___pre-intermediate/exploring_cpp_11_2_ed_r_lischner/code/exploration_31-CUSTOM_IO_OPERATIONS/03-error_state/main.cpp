#include <cstdlib>
#include <cassert>
#include <ios>
#include <iostream>
#include <sstream>
#include <limits>

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

std::istream& operator>>(std::istream& in, rational& rat) {
    int n{ 0 }, d{ 0 };
    char sep{ '\0' };
    if (not (in >> n >> sep))
        in.setstate(std::cin.failbit);
    else if (sep != '/') {
        in.unget();
        rat.assign(n, 1);
    }
    else if (in >> d)
        rat.assign(n, d);
    else
        in.setstate(std::cin.failbit);

    return in;
}

std::ostream& operator<<(std::ostream& out, rational const& rat) {
    std::ostringstream tmp{};
    tmp << rat.numerator;
    if (1 != rat.denominator)
        tmp << '/' << rat.denominator;
    out << tmp.str();

    return out;
}

bool iofailure(std::istream& in) {
    return in.fail() and not in.bad();
}

int main() {
    rational r{ 0 };

    while (std::cin) {
        if (std::cin >> r)
            std::cout << r << '\n';
        else if (iofailure(std::cin)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    }
    if (std::cin.bad())
        std::cerr << "Unrecoverable input failure\n";

    return 0;
}

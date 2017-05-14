#include <cstdlib>
#include <cassert>
#include "test.hpp"

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

bool operator==(rational const a, rational const& b) {
    return a.numerator == b.numerator 
           and 
           a.denominator == b.denominator;
}

inline bool operator!=(rational const& a, rational const& b) {
    return not (a == b);
}

bool operator<(rational const& a, rational const& b) {
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

inline bool operator<=(rational const& a, rational const& b) {
    return not (b < a);
}

inline bool operator>(rational const& a, rational const& b) {
    return b < a;
}

inline bool operator >=(rational const& a, rational const& b) {
    return not (b > a);
}


int main() {
    rational a{ 60, 5 };
    rational b{ 12, 1 };
    rational c{ -24, -2 };
    TEST(a == b);
    TEST(a >= b);
    TEST(a <= b);
    TEST(b <= a);
    TEST(b >= a);
    TEST(b == c);
    TEST(b >= c);
    TEST(b <= c);
    TEST(a == c);
    TEST(a >= c);
    TEST(a >= c);
    TEST(a <= c);

    rational d{ 109, 10 };
    TEST(d < a);
    TEST(d <= a);
    TEST(d != a);
    TEST(a > d);
    TEST(a >= d);
    TEST(a != d);

    rational e{ 241, 20 };
    TEST(e > a);
    TEST(e >= a);
    TEST(a < e);
    TEST(a <= e);
    TEST(a != e);

    return 0;
}

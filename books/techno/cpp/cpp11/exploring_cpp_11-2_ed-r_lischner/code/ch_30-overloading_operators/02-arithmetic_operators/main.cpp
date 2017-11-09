#include <cstdlib>
#include <cassert>

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

// arithmetic operators
rational operator+(rational const& lhs, rational const& rhs) {
    return rational{ lhs.numerator * rhs.denominator 
                     + rhs.numerator * lhs.denominator,
                     lhs.denominator * rhs.denominator };
}

rational operator-(rational const& r) {
    return rational{ -r.numerator, r.denominator };
}

rational operator-(rational const& lhs, rational const& rhs) {
    return rational{ lhs.numerator * rhs.denominator
                     - rhs.numerator * lhs.denominator,
                     lhs.denominator * rhs.denominator };
}

rational operator*(rational const& lhs, rational const& rhs) {
    return rational{ lhs.numerator * rhs.numerator,
                     lhs.denominator * rhs.denominator };
}

rational operator/(rational const& lhs, rational const& rhs) {
    return rational{ lhs.numerator * rhs.denominator,
                     lhs.denominator * rhs.numerator };
}


int main() {
    return 0;
}

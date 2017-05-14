#include <cstdlib>
#include <cassert>
#include <iostream>

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

    float as_float() {
        return static_cast<float>(numerator) / denominator;
    }

    double as_double() {
        return numerator / static_cast<double>(denominator);
    }

    long double as_long_double() {
        return static_cast<long double>(numerator) /
               static_cast<long double>(denominator);
    }

    int numerator;
    int denominator;
};


int main() {
    rational pi{ 355, 113 };
    rational bmi{ 90 * 100 * 100, 180 * 180 };
    double circumference{ 0 } , radius{ 10 };

    circumference = 2 * pi.as_double() * radius;
    std::cout << "circumference of circle with radius "
              << radius << " is about " 
              << circumference << '\n';

    std::cout << "bmi = " << bmi.as_float() << '\n';

    return 0;
}

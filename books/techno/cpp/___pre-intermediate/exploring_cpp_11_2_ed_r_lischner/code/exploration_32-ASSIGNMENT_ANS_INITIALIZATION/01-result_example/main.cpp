#include <cassert>
#include <cstdlib>
#include <istream>
#include <ostream>
#include <sstream>


int gcd(int n, int m)
{
    n = std::abs(n);
    while (m != 0) {
        int tmp(n % m);
        n = m;
        m = tmp;
    }
    return n;
}


struct rational
{
    rational()
    : numerator{0}, denominator{1}
    {/*empty*/}

    rational(int num)
    : numerator{num}, denominator{1}
    {/*empty*/}

    rational(int num, int den)
    : numerator{num}, denominator{den}
    {
        reduce();
    }

    rational(double r)
    : rational{static_cast<int>(r * 10000), 10000}
    {/*empty*/}

    rational& operator=(rational const& that)
    {
        this->numerator = that.numerator;
        this->denominator = that.denominator;
        reduce();
        return *this;
    }

    float as_float()
    {
        return static_cast<float>(numerator) / denominator;
    }

    double as_double()
    {
        return static_cast<double>(numerator) / denominator;
    }

    long double as_long_double()
    {
        return static_cast<long double>(numerator) / 
                     denominator;
    }

    void assign(int num, int den)
    {
        numerator = num;
        denominator = den;
        reduce();
    }

    void reduce()
    {
        assert(denominator != 0);
        if (denominator < 0)
        {
            denominator = -denominator;
            numerator = -numerator;
        }
        int div{gcd(numerator, denominator)};
        numerator = numerator / div;
        denominator = denominator / div;
    }

    int numerator;
    int denominator;
};

rational abs(rational const& r)
{
    return rational{std::abs(r.numerator), r.denominator};
}

rational operator-(rational const& r)
{
    return rational{-r.numerator, r.denominator};
}

rational operator+(rational const& lhs, rational const& rhs)
{
    return rational{lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
                                    lhs.denominator * rhs.denominator};
}

rational operator-(rational const& lhs, rational const& rhs)
{
    return rational{lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
                                    lhs.denominator * rhs.denominator};
}

rational operator*(rational const& lhs, rational const& rhs)
{
    return rational{lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator};
}

rational operator/(rational const& lhs, rational const& rhs)
{
    return rational{lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator};
}

bool operator==(rational const& a, rational const& b)
{
    return a.numerator == b.numerator and a.denominator == b.denominator;
}

inline bool operator!=(rational const& a, rational const& b)
{
    return not (a == b);
}

bool operator<(rational const& a, rational const& b)
{
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

inline bool operator<=(rational const& a, rational const& b)
{
    return not (b < a);
}

inline bool operator>(rational const& a, rational const& b)
{
    return b < a;
}

inline bool operator>=(rational const& a, rational const& b)
{
    return not (b > a);
}

std::istream& operator>>(std::istream& in, rational& rat)
{
    int n{0}, d{0};
    char sep{'\0'};
    if (not (in >> n >> sep))
        in.setstate(in.failbit);
    else if (sep != '/')
    {
        in.unget();
        rat.assign(n, 1);
    }
    else if (in >> d)        
        rat.assign(n, d);
    else
        in.setstate(in.failbit);

    return in;
}


std::ostream& operator<<(std::ostream& out, rational const& rat)
{
    std::ostringstream tmp{};
    tmp << rat.numerator << '/' << rat.denominator;
    out << tmp.str();

    return out;
}


int main() {
    return 0;
}
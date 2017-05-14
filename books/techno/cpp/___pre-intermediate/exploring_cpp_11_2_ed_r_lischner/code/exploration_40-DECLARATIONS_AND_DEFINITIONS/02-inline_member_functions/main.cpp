#include <cassert>

class rational {
    public:
        rational();
        rational(int num);
        inline rational(int num, int den);

        void assign(int num, int den);

        int numerator() const { return numerator_; }
        int denominator() const { return denominator_; }

        rational& operator=(int num);

    private:
        void reduce();
        int numerator_;
        int denominator_;
};

int gcd(int n, int m) {
    if (n < 0)
        n = -n;
    while (m != 0) {
        int tmp{ n % m };
        n = m;
        m = tmp;
    }

    return n;
}


rational::rational() 
: rational{ 0 } { }

rational::rational(int num)
: numerator_{ num }, denominator_{ 1 } { }

inline rational::rational(int num, int den)
: numerator_{ num }, denominator_{ den }
{
    reduce();
}

void rational::reduce() {
    assert(0 != denominator_);
    if (denominator_ < 0) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    int div{ gcd(numerator_, denominator_) };
    numerator_ /= div;
    denominator_ /= div;
}

void rational::assign(int num, int den) {
    numerator_ = num;
    denominator_ = den;
    reduce();
}

rational& rational::operator=(int num) {
    numerator_  = num;
    denominator_ = 1;
    return *this;
}

int main() {
    rational r{ 1, 2 };

    return 0;
}

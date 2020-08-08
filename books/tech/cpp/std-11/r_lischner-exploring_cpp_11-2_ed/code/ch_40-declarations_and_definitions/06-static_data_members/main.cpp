#include <cassert>

class rational {
    public:
        rational();
        rational(int num);
        rational(int num, int den);

        void assign(int num, int den);

        int numerator() const;
        int denominator() const;

        rational& operator=(int num);

        static const rational zero;
        static const rational one;
        static const rational pi;

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

rational::rational(int num, int den)
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

int rational::numerator() const { return numerator_; }

int rational::denominator() const { return denominator_; }

rational& rational::operator=(int num) {
    numerator_  = num;
    denominator_ = 1;
    return *this;
}

const rational rational::zero{};
const rational rational::one{ 1 };
const rational rational::pi{ 355, 113 };


int main() {
    rational r{ rational::zero };

    return 0;
}

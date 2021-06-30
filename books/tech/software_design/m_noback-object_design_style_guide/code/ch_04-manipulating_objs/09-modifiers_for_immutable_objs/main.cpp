#include <cassert>
#include <cmath>
namespace workspace {

class DiscountPercentage {
public:
    DiscountPercentage(const int percentage) : percentage_(percentage) {}

    int percentage() const { return percentage_; }

private:
    const int percentage_;
};


class Money {
public:
    static Money fromInt(const int cents) { return Money(cents); }

    Money withDiscountApplied(const DiscountPercentage& discountPercentage) const {
        const int discount = (int)std::round(
            (discountPercentage.percentage() / 100.0) * this->amountInCents());          

        return Money::fromInt(this->amountInCents() - discount);
    }

    int amountInCents() const { return amountInCents_; }

    friend bool operator == (const Money& lhs, const Money& rhs);

private:
    Money(const int amountInCents) : amountInCents_(amountInCents) {}

    const int amountInCents_;
};

bool operator == (const Money& lhs, const Money& rhs) { 
    return lhs.amountInCents_ == rhs.amountInCents_;
}


void run() {    
    assert((Money::fromInt(1800) ==
        Money::fromInt(2000).withDiscountApplied(
            DiscountPercentage(10))));
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}

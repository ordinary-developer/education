#include <string>
#include <cassert>
namespace workspace {

class Amount {
public:
    Amount(const int val) : val_(val) {}

    int value() const { return val_; }

private:
    const int val_;
};

class Currency {
public:
    Currency(const std::string& val) : val_(val) {}

    std::string value() const { return val_; }

private:
    const std::string val_;
};

class Money {
public:
    Money(const Amount& amount, const Currency& currency)
        : amount_(amount), currency_(currency) {}

    Amount amount() const { return amount_; }
    Currency currency() const { return currency_; }

private:
    const Amount amount_;
    const Currency currency_;
};



class ExchangeRate {
public:
    ExchangeRate(
        const Currency& fromCurrency, 
        const Currency& targetCurrency,
        int rate)
        : fromCurrency_(fromCurrency), targetCurrency_(targetCurrency), rate_(rate)
    {}

    Money convert(const Amount& amount) const {
        return Money(rate_ * amount.value(), targetCurrency_);
    }

    
private:
    const Currency fromCurrency_;
    const Currency targetCurrency_;
    const int rate_;    
};


void run() {
    Money convertedToUsd = 
        ExchangeRate(Currency("other"), Currency("USD"), 2)
            .convert(Amount(10));
    assert(20 == convertedToUsd.amount().value());

    Money convertedFromUsd =
        ExchangeRate(Currency("USD"), Currency("other"), 1)
            .convert(Amount(10));
    assert(10 == convertedFromUsd.amount().value());    
}

} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl; workspace::run(); std::cout << std::endl;

    return 0;
}

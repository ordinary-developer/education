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



class ExchangeRate {
public:
    ExchangeRate(const int rate, const Currency& targetCurrency)
        : rate_(rate), targetCurrency_(targetCurrency) 
    {}

    Amount convert(const Amount& amount) const {
        return Amount(rate_ * amount.value());
    }
    
private:
    const int rate_;
    const Currency targetCurrency_;
};

class ExchangeRateProvider {
public:
    ExchangeRate getRateFor(
        const Currency& sourceCurrency, const Currency& targetCurrency) const
    {
        return ExchangeRate(
            (sourceCurrency.value() == "USD" ? 1 : 2), 
            targetCurrency);
    }
};



class Money {
public:
    Money(const Amount& amount, const Currency& currency)
        : amount_(amount), currency_(currency) {}

    Money convert(
        const ExchangeRateProvider& exchangeRateProvider,
        const Currency& targetCurrency) const
    {
        const Amount targetAmount = 
            exchangeRateProvider
                    .getRateFor(this->currency(), targetCurrency)
                    .convert(this->amount());
        return Money(targetAmount, targetCurrency);
    }

    Amount amount() const { return amount_; }
    Currency currency() const { return currency_; }

private:
    const Amount amount_;
    const Currency currency_;
};


void run() {
    Money convertedToUsd = Money(Amount(10), Currency("other"))
        .convert(ExchangeRateProvider(), Currency("USD"));
    assert(20 == convertedToUsd.amount().value());

    Money convertedFromUsd = Money(Amount(10), Currency("USD"))
        .convert(ExchangeRateProvider(), Currency("other"));
    assert(10 == convertedFromUsd.amount().value());
}

} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl; workspace::run(); std::cout << std::endl;

    return 0;
}

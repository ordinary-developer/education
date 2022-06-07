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
    ExchangeRate(const int rate) : rate_(rate) {}

    Amount applyTo(const Amount& amount) const { return rate_ * amount.value(); }

private:
    const int rate_;
};

class ExchangeRateProvider {
public:    
    ExchangeRate getRateFor(const Currency& sourceCurrency, const Currency& targetCurrency) const {
        return ExchangeRate(2);
    }
};

class ExchangeService {
public:
    ExchangeService(const ExchangeRateProvider& exchangeRateProvider)
        : exchangeRateProvider_(exchangeRateProvider)
    {}

    Money convert(const Money& money, const Currency& currency) const {
        const ExchangeRate rate = exchangeRateProvider_.getRateFor(
            money.currency(), currency);

        return Money(rate.applyTo(money.amount()), currency);
    }

private:
    const ExchangeRateProvider exchangeRateProvider_;
};



void run() {
    const Money converted = ExchangeService(ExchangeRateProvider()).convert(
        Money(Amount(10), Currency("other")),
        Currency("USD"));

    assert(20 == converted.amount().value());
}

} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl; workspace::run(); std::cout << std::endl;

    return 0;
}

#include <string>
#include <stdexcept>
#include <cassert>
namespace workspace {


class Amount {
public:
	Amount(const int value) : value_(value) {}

private:
	const int value_;
};


class Currency {
public:
	Currency(const std::string& value) : value_(value) {}

private:
	const std::string value_;
};

class Money {
public:
	static Money create(const int amount, const std::string& currency) {
		return Money(Amount(amount), Currency(currency));
	}

private:
    Money(const Amount& amount, const Currency& currency)
        : amount_(amount), currency_(currency) {}

    const Amount amount_;
    const Currency currency_;
};

class Product {
public:
    Product(const Money& money) : money_(money) {}

private:
    Money money_;
};

class Converter {
public:
    Money convert(const Money& money) const {
        return Money::create(100, "EUR");
    }
};


void run() {
    {
        Money::create(100, "USD");
    }
    
    {
        Product(Money::create(100, "USD"));
    }    
    
    {
        Converter().convert(Money::create(100, "USD"));
    }
}

} // workspace


int main() {
    workspace::run();

    return 0;
}

#include <cassert>
namespace workspace {

class Quantity {
public:
    Quantity static fromInt(const int quantity, const int precision) {
        return Quantity(quantity, precision);
    }

    Quantity add(const Quantity& other) const {
        assert(precision_ == other.precision_);
        return Quantity(quantity_ + other.quantity_, precision_);
    }

private:
    Quantity(const int quantity, const int precision)    
        : quantity_(quantity), precision_(precision) {}

    const int quantity_;
    const int precision_;
};

void run() {
    const Quantity quantity = Quantity::fromInt(10, 2).add(Quantity::fromInt(20, 2));
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}

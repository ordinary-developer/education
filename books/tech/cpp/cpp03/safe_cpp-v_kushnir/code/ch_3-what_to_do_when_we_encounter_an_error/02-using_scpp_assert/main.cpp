#include <iostream>
#include "scpp_assert.hpp"

int main(int argc, char* argv[]) {
    std::cout << "Hello, SCPP_ASSERT" << std::endl;

    double stock_price{ 100.0 };
    SCPP_ASSERT(0. < stock_price && stock_price <= 1.e6,
                "Stock price " << stock_price << " is out of range");

    stock_price = -1.0;
    SCPP_ASSERT(0. < stock_price && stock_price <= 1.e6,
                "Stock price " << stock_price << " is out of range");

    return 0;
}


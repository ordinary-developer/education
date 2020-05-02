#include <iostream>
#include "scpp_assert.hpp"


int main() {
    std::cout << "Hello, SCPP_ASSERT" << std::endl;
    try {
        double stock_price{ 100.0 };
        SCPP_ASSERT(
            0 < stock_price && stock_price <= 1e6,
            "Stock price " << stock_price << " is out of range.");

        stock_price = -1.;
        SCPP_ASSERT(
            0 < stock_price && stock_price <= 1e6,
            "Stock price " << stock_price << " is out of range.");
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception caught in " << __FILE__ 
                  << " #" << __LINE__ << ":\n" 
                  << ex.what() << std::endl;
    }

    return 0;
}

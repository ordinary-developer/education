#include <stdexcept>
#include <string>
#include <cassert>
namespace workspace {

struct Assertion {

template <typename T>
static void greaterThanOrEqual(const T& lhs, const T& rhs) {
    if (lhs < rhs)
        throw std::invalid_argument(std::string());
}

template <typename T>
static void greaterThan(const T& lhs, const T& rhs) {
    if (lhs <= rhs)
        throw std::invalid_argument(std::string());
}

};

class PriceRange {
public:
    PriceRange(const int minPrice, const int maxPrice)
        : minPrice_(minPrice), maxPrice_(maxPrice)
    {
        Assertion::greaterThanOrEqual(minPrice_, 0);
        Assertion::greaterThanOrEqual(maxPrice_, 0);
        Assertion::greaterThan(maxPrice_, minPrice_);
    }

private:
    const int minPrice_;
    const int maxPrice_;
};

void run_with_exception(const int minPrice, const int maxPrice) {
    bool wasEx = false;

    try {
        PriceRange(minPrice, maxPrice);
    }    
    catch (const std::invalid_argument&) { assert((wasEx = true)); }
    catch (...) { assert(false); }

    assert(wasEx);
}


void run() {

{
  PriceRange(100, 200);
  assert(true);
}

{
  run_with_exception(-100, 200); 
  run_with_exception(100, -200); 
  run_with_exception(200, 100); 
  assert(true);
}

}


} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl; workspace::run(); std::cout << std::endl;

    return 0;
}

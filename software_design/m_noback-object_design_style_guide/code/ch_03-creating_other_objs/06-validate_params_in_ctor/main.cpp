#include <stdexcept>
#include <cassert>
namespace workspace {

class PriceRange {
public:
    PriceRange(const int minPrice, const int maxPrice)
        : minPrice_(minPrice), maxPrice_(maxPrice)
    {
        if (minPrice_ < 0)
            throw std::invalid_argument("min price in invalid");
        if (maxPrice_ < 0)
            throw std::invalid_argument("max price is invalid");
        if (minPrice_ > maxPrice_)
            throw std::invalid_argument("min price is larger than max price");
    }

private:
    const int minPrice_;
    const int maxPrice_;
};

void run_with_exception(const int minPrice, const int maxPrice) {
    bool wasException = false;

    try {
        PriceRange(minPrice, maxPrice);
    }
    catch (const std::invalid_argument&) { assert((wasException = true)); }
    catch (...) { assert((false)); }

    assert((wasException));
}

void run() {
    {
        run_with_exception(-100, 200);
        run_with_exception(100, -200);
        run_with_exception(200, 100);
    }

    {
        PriceRange(100, 200);
        assert((true));
    }
}

} // workspace


int main() {
    workspace::run();
    
    return 0;
}

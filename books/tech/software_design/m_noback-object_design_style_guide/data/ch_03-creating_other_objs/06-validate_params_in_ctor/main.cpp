#include <stdexcept>
#include <cassert>
namespace workspace {

class PriceRange {
public:
    PriceRange(const int minPrice, const int maxPrice)
        : _minPrice(minPrice), _maxPrice(maxPrice)
    {
        if (_minPrice < 0)
            throw std::invalid_argument("min price in invalid");
        if (_maxPrice < 0)
            throw std::invalid_argument("max price is invalid");
        if (_minPrice > _maxPrice)
            throw std::invalid_argument("min price is larger than max price");
    }

private:
    const int _minPrice;
    const int _maxPrice;
};

void _run_with_exception(const int minPrice, const int maxPrice) {
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
        _run_with_exception(-100, 200);
        _run_with_exception(100, -200);
        _run_with_exception(200, 100);
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

#include <stdexcept>
#include <cassert>
namespace workspace {

class Deal {
public:
    Deal(const int firstPartyAmount, const int secondPartyAmount)
        : _firstPartyAmount(firstPartyAmount), _secondPartyAmount(secondPartyAmount)
    {
        if (_firstPartyAmount <= 0)
            throw std::invalid_argument("invalid the first party amount");
        if (_secondPartyAmount <= 0)
            throw std::invalid_argument("invalid the second party amount");
    }

    int totalAmount() const { return _firstPartyAmount + _secondPartyAmount; }

private:
    const int _firstPartyAmount;
    const int _secondPartyAmount;
};

void run() {
    {
        assert((300 == Deal(100, 200).totalAmount()));
    }


    {
        bool wasException = false;

        try {
            Deal(-100, 100);
        }
        catch (const std::invalid_argument&) { assert((wasException = true)); }
        catch (...) { assert((false)); }

        assert((wasException));
    }


    {
        bool wasException = false;

        try {
            Deal(100, -100);
        }
        catch (const std::invalid_argument&) { assert((wasException = true)); }
        catch (...) { assert((false)); }

        assert((wasException));
    }
}

} // workspace


int main() {
    workspace::run();
    return 0;
}

#include <stdexcept>
#include <cassert>
namespace workspace {

class Deal {
public:
    Deal(const int firstPartyAmount, const int secondPartyAmount)
        : firstPartyAmount_(firstPartyAmount), secondPartyAmount_(secondPartyAmount)
    {
        if (firstPartyAmount_ <= 0)
            throw std::invalid_argument("invalid the first party amount");
        if (secondPartyAmount_ <= 0)
            throw std::invalid_argument("invalid the second party amount");
    }

    int totalAmount() const { return firstPartyAmount_ + secondPartyAmount_; }

private:
    const int firstPartyAmount_;
    const int secondPartyAmount_;
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

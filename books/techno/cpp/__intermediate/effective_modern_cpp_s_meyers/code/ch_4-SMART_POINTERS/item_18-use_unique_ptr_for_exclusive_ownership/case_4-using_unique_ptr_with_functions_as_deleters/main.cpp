#include <memory>

class Investment {
    public:
        virtual ~Investment() = default;
};

class Stock : public Investment { };

class Bond : public Investment { };

class RealEstate : public Investment { };

// a stub function
void makeLogEntry(Investment* logEntry) {
    // do nothing
};

void delInvestment(Investment* pInvestment) {
    makeLogEntry(pInvestment);
    delete pInvestment;
}

template<typename... Ts>
std::unique_ptr<Investment, void (*)(Investment*)>
makeInvestments(Ts&&... params) {
    std::unique_ptr<Investment, void (*)(Investment*)>
      pInv(nullptr, delInvestment);

    pInv.reset(new Stock());

    return pInv;
}

int main() {
    
    return 0;
}

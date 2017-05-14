#include <memory>

class Investment {
    public:
    	virtual ~Investment() = default;
};

class Stock : public Investment { };

class Bond : public Investment { };

class RealEstate : public Investment { };

// a stub function
void makeLogEntry(Investment* pInvestment) {
    // do nothing
}

template<typename... Ts>
auto makeInvestment(Ts&&... params) {
    auto delInvmt = [](Investment* pInvestment)
                    {
		      makeLogEntry(pInvestment);
		      delete pInvestment;
		    };
    std::unique_ptr<Investment, decltype(delInvmt)>
        pInv(nullptr, delInvmt);

    pInv.reset(new Stock());

    return pInv;
}

int main() {

    return 0;
}

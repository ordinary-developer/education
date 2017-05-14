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


auto delInvmt = [](Investment* pInvestment) {
		    makeLogEntry(pInvestment);
		    delete pInvestment;
    		};
		  
template<typename... Ts>
std::unique_ptr<Investment, decltype(delInvmt)>
makeInvestment(Ts&&... params) {
  std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);

  pInv.reset(new Stock());
}

int main() {

    return 0;
}

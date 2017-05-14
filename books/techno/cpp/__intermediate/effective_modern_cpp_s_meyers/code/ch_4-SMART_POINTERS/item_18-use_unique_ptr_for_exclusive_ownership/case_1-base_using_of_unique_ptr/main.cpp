#include <memory>

class Investment { };

class Stock : public Investment { };

class Bond : public Investment { };

class RealEstate : public Investment { };

template<typename... Ts>
std::unique_ptr<Investment> makeInvestment(Ts&&... params)
{
    return std::make_unique<Stock>();
}

int main() {
    return 0;
}

#include <stdexcept>
#include <string>

#include <cassert>
#include <cmath>
namespace workspace {

class DecimalValue {
public:
    static DecimalValue fromInt(const int val, const int precision) {
        return DecimalValue(val, precision);
    }

    static DecimalValue fromFloat(const float val, const int precision) {
        return DecimalValue(
            (int)std::round(val * std::pow(10, precision)),
            precision);
    }

    static DecimalValue fromStr(const std::string& str) {
        const std::size_t periodPos = str.find(".");
        if (std::string::npos == periodPos) {
            throw std::invalid_argument(std::string());
        }

        const std::string whole = str.substr(0, periodPos);
        const std::string fract = str.substr(periodPos + 1);
        const std::string raw = whole + fract;

        return DecimalValue(std::stoi(raw), fract.size());
    }

    int whole() const { return val_ / (int)std::pow(10, precision_); }
    int fractional() const { return val_ % (int)std::pow(10, precision_); }

private:
    DecimalValue(const int val, const int precision)
        : val_(val), precision_(precision)
    {
        if (precision_ < 0)
            throw std::invalid_argument(std::string());
    }

    const int val_;
    const int precision_;
};

void run() {
  {
    const DecimalValue decVal = DecimalValue::fromInt(12345, 2);
    assert((123 == decVal.whole() && 45 == decVal.fractional()));
  }

  {
    const DecimalValue decVal = DecimalValue::fromFloat(123.45000, 2);
    assert((123 == decVal.whole() && 45 == decVal.fractional()));
  }

  {
    const DecimalValue decVal = DecimalValue::fromStr("123.45");
    assert((123 == decVal.whole() && 45 == decVal.fractional()));
  }
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}

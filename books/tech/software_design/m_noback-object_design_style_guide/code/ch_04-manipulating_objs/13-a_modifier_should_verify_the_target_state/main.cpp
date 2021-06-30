	#include <stdexcept>
#include <cassert>
namespace workspace {

class Fraction {
public:
    Fraction(const int numerator, const int denominator) 
        : numerator_(numerator), denominator_(denominator)
    {
        if (0 == denominator_)
            throw std::invalid_argument("@denominator is invalid");
    }

    Fraction withDenominator(const int denominator) const { return Fraction(numerator_, denominator); }
    
private:
    const int numerator_;
    const int denominator_;
};


void run() {
  {
    bool wasEx = false;
    try {
        Fraction(1, 2).withDenominator(3);
    }
    catch (...) { wasEx = true; }
    assert(!wasEx);
  }

  {
    bool wasEx = false;
    try {
        Fraction(1, 2).withDenominator(0);
    }      
    catch (const std::invalid_argument&) { wasEx = true; } 
    assert(wasEx);
  }

}
} // workspace

#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl;
    workspace::run();
    std::cout << std::endl;

    
    return 0;
}

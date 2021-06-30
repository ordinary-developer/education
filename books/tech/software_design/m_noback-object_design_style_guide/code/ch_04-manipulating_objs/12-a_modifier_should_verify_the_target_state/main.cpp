#include <stdexcept>
#include <cassert>
namespace workspace {

class TotalDistanceTraveled {
public:
    TotalDistanceTraveled(const int totalDistance) : totalDistance_(totalDistance) {}

    TotalDistanceTraveled add(const int distance) const {
        if (distance < 0)
            throw std::invalid_argument("@distance is invalid");
        
        return TotalDistanceTraveled(totalDistance_ + distance);
    }

private:
    const int totalDistance_;
};

void run() {
  {
    bool wasEx = false;
    try {
        TotalDistanceTraveled(0);
    }    
    catch (...) { wasEx = true; }
    assert(!wasEx);
  }

  {
    bool wasEx = false;
    try {
        TotalDistanceTraveled(0).add(-42);
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
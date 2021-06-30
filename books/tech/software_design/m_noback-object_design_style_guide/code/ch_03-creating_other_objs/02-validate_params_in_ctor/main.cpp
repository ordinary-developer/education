#include <stdexcept>
#include <cassert>
namespace workspace {

class Coords {
public:
    Coords(const double latitude, const double longitude) : latitude_(latitude), longitude_(longitude) 
    {
        if (latitude _> 90 || latitude_ < -90)
            throw std::invalid_argument("latitude should be between -90 and 90");
        if (longitude_ > 180 || longitude_ < -180)
            throw std::invalid_argument("longitude should be between -180 and 180");
    }

private:
    const double latitude_;
    const double longitude_;
};

void run() {
    bool wasException = false;
    try {
        Coords(-100, 200);
    }
    catch (const std::invalid_argument&) { assert((wasException = true)); }
    catch (...) { assert((false)); }

    assert((wasException));
}

} // workspace


int main() {
    workspace::run();
    return 0;
}

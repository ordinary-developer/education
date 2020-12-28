#include <stdexcept>
#include <cassert>
namespace workspace {

class Coords {
public:
    Coords(const double latitude, const double longitude) : _latitude(latitude), _longitude(longitude) 
    {
        if (_latitude > 90 || _latitude < -90)
            throw std::invalid_argument("latitude should be between -90 and 90");
        if (_longitude > 180 || _longitude < -180)
            throw std::invalid_argument("longitude should be between -180 and 180");
    }

private:
    const double _latitude;
    const double _longitude;
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

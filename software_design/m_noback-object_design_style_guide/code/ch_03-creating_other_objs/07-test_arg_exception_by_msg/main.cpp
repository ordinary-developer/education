#include <string>
#include <stdexcept>
#include <cassert>
namespace workspace {

class Coords {
public:
    Coords(const double latitude, const double longitude)
        : latitude_(latitude), longitude_(longitude)
    {
        const bool isLatitudeInvalid = latitude_ > 90 || latitude_ < -90;
        const bool isLongitudeInvalid = longitude_ > 180 || longitude_ < -180;

        if (isLatitudeInvalid && isLongitudeInvalid)
            throw std::invalid_argument(
                "both the latitude and longitude are invalid");
        if (isLatitudeInvalid)
            throw std::invalid_argument(
                "the latitude is invalid");
        if (isLongitudeInvalid)
            throw std::invalid_argument(
                "the longitude is invalid");
    }

private:
    const double latitude_;
    const double longitude_;
};

void run() {
    {
        bool wasException = false;

        try {
            Coords(90.1, 180.1);
        }
        catch (const std::invalid_argument& e) { 
            assert((std::string("both the latitude and longitude are invalid") == std::string(e.what())));
            assert((wasException = true)); 
        }
        catch (...) { assert((false)); }

        assert((wasException));
    }

    {
        bool wasException = false;

        try {
            Coords(90.1, 0);
        }
        catch (const std::invalid_argument& e) { 
            assert((std::string("the latitude is invalid") == std::string(e.what())));
            assert((wasException = true)); 
        }
        catch (...) { assert((false)); }

        assert((wasException));
    }

    {
        bool wasException = true;

        try {
            Coords(0, 180.1);
        }
        catch (const std::invalid_argument& e) { 
            assert((std::string("the longitude is invalid") == std::string(e.what())));
            assert((wasException = true)); 
        }
        catch (...) { assert((false)); }

        assert((wasException));
    }
}

} // workspace


int main() {
    workspace::run();

    return 0;
}

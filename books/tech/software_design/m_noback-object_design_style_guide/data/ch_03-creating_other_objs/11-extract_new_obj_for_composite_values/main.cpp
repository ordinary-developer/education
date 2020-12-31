#include <string>
#include <stdexcept>
#include <cassert>
namespace workspace {


class Distance {
public:
    Distance(const int distance, const std::string unit) 
        : distance_(distance), unit_(unit) 
    {
        if (distance <= 0)
            throw std::invalid_argument(
                "distance should be greater than 0");

        if (KNOWN_UNITS[0] != unit_ && KNOWN_UNITS[1] != unit_)
            throw std::invalid_argument(
                std::string("unknown unit ").append(unit_));
    }

private:
    static const std::string KNOWN_UNITS[2];

    const int distance_;
    const std::string unit_;
};
const std::string Distance::KNOWN_UNITS[2] = { "meters", "feet" };


class Run {
public:
    Run(const Distance& distance) : distance_(distance) {}

private:
    const Distance distance_;
};

void run() {
    Distance(100, "meters");
    Distance(100, "feet");

    Run(Distance(100, "meters"));

    {
        bool wasException = false;

        try {
            Distance(0, "meters");
        }
        catch (const std::invalid_argument& e) {
            assert((std::string("distance should be greater than 0") 
                == std::string(e.what())));
            assert((wasException = true));
        }
        catch (...) { assert((false)); }

        assert((wasException));        
    }

    {
        bool wasException = false;

        try {
            Distance(100, "ABC");
        }
        catch (const std::invalid_argument& e) {
            assert((std::string("unknown unit ").append("ABC")
                == std::string(e.what())));
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

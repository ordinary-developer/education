#include <stdexcept>
#include <cassert>
namespace workspace {

class Line {
public:
    static Line dotted(const int distanceBetweenDots) {
        if (distanceBetweenDots <= 0)
            throw std::invalid_argument("invalid distance between dots");

        return Line(true, distanceBetweenDots);
    }

    static Line solid() {
        return Line(false, -1);
    }

private:
    Line(const bool isDotted, const int distanceBetweenDots) 
        : _isDotted(isDotted), _distanceBetweenDots(distanceBetweenDots)
    {}

    const bool _isDotted;
    const int _distanceBetweenDots;
};

void run() {
    {
        bool wasException = true;

        try {
            Line::dotted(-10);
        }
        catch (const std::invalid_argument&) { assert((wasException = true)); }
        catch (...) { assert((false)); }

        assert((wasException));
    }

    {
        Line::solid();
        assert((true));
    }
}

} // workspace


int main() {
    workspace::run();
    return 0;
}

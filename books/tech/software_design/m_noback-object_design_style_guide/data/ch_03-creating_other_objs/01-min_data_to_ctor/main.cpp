#include <cmath>
#include <cassert>
namespace workspace {

class Position {
public:
    Position(const int x, const int y) : _x(x), _y(y) {}

    double distanceTo(const Position& other) const {
        return std::sqrt(std::pow(other._x - _x, 2) + std::pow(other._y - _y, 2));
    }

private:
    const int _x;
    const int _y;
}; 

void run() {
    const Position pos1(45, 60);
    const Position pos2(60, 45);

    const double actual = pos1.distanceTo(pos2);

    const double delta = 0.001;
    const double expected = 21.213;
    assert((actual <= expected + delta && actual >= expected - delta));
}

} // workspace

int main() {
    workspace::run();
    return 0;
}

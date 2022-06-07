#include <cmath>
#include <cassert>
namespace workspace {

class Position {
public:
    Position(const int x, const int y) : x_(x), y_(y) {}

    double distanceTo(const Position& other) const {
        return std::sqrt(std::pow(other.x_ - x_, 2) + std::pow(other.y_ - y_, 2));
    }

private:
    const int x_;
    const int y_;
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

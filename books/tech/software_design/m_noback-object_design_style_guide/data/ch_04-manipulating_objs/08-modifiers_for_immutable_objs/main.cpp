#include <cassert>
namespace workspace {

class Position {
public:
    Position(const int x, const int y) : x_(x), y_(y) {}

    Position clone() const { return Position(x_, y_); }

    Position toTheLeft(const int steps) const { 
        Position ret = clone();
        ret.x_ -= steps;
        return ret;
    }

    friend bool operator == (const Position& lhs, const Position& rhs);

private:
    int x_;
    int y_;
};
bool operator == (const Position& lhs, const Position& rhs) {
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

void run() {
    assert((Position(25, 1) == Position(42, 1).toTheLeft(17)));
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}

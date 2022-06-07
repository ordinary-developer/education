#include <cassert>
namespace workspace {

class Position {
public:
    Position(const int x, const int y) : x_(x), y_(y) {}

    Position moveLeft(const int steps) const { return Position(x_ - steps, y_); }

    friend bool operator == (const Position&, const Position&);
private:
    const int x_;
    const int y_;
};
bool operator == (const Position& lhs, const Position& rhs) {
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

void run() {
    assert((Position(25, 0) == Position(42, 0).moveLeft(17)));
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}

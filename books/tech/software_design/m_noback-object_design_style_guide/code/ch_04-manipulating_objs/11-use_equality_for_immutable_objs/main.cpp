#include <cassert>
namespace workspace {

class Position {
public:
    Position(const int x, const int y) : x_(x), y_(y) {}

    Position toTheLeft(const int steps) const { return Position(x_ - steps, y_); }

    friend bool operator == (const Position&, const Position&);

private:
    int x_;
    int y_;
};
bool operator == (const Position& lhs, const Position& rhs) {
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}


class Player {
public:
    Player(const Position& position) : position_(position) {}

    void moveLeft(const int steps) { position_ = position_.toTheLeft(steps); }

    Position currentPosition() const { return position_; }

private:
    Position position_;
};


void run() {
    Player player(Position(42, 1));

    player.moveLeft(17);

    assert((Position(25, 1) == player.currentPosition()));
}

} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}

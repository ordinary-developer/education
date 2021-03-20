#include <cassert>
namespace workspace {

class Position {
public:
    Position(const int x, const int y) : x_(x), y_(y) {}

    Position clone() const { return Position(x_, y_); }

    Position withX(const int x) const { 
        Position ret = clone();
        ret.x_ = x;
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
    assert((Position(2, 1) == Position(1, 1).withX(2)));
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}

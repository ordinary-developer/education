#include <cmath>

struct point {
    point()
        : point{ 0.0, 0.0 } { }

    point(double x, double y)
        : x_{ x }, y_{ y } { }

    point(point const&) = default;

    double distance() {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    double angle() {
        return std::atan2(y_, x_);
    }

    void offset(double off) {
        offset(off, off);
    }

    void offset(double xOffset, double yOffset) {
        x_ += xOffset;
        y_ += yOffset;
    }

    void scale(double multiplier) {
        scale(multiplier, multiplier);
    }

    void scale(double xMultiplier, double yMultiplier) {
        x_ *= xMultiplier;
        y_ *= yMultiplier;
    }

    double x_;
    double y_;
};


int main() {
    return 0;
}

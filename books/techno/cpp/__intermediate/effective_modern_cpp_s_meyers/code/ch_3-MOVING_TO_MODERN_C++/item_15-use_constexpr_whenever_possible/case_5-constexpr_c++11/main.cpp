class Point {
    public:
        constexpr Point(double xVal = 0, double yVal = 0) noexcept 
            : x(xVal), y(yVal) { }

        constexpr double xValue() const noexcept { return x; }
        constexpr double yValue() const noexcept { return y; }

        void setX(double newX) noexcept { x = newX; }
        void setY(double newY) noexcept { y = newY; }

    private:
        double x, y;
};

constexpr Point midpoint(const Point& p1, const Point& p2) noexcept {
    return { (p1.xValue() + p2.xValue()) / 2,
             (p2.yValue() + p2.yValue()) / 2 };
}

int main() { 
    constexpr Point p1(9.4, 27.7);
    constexpr Point p2(28.8, 5.3);

    constexpr auto mid = midpoint(p1, p2);

    return 0;
}

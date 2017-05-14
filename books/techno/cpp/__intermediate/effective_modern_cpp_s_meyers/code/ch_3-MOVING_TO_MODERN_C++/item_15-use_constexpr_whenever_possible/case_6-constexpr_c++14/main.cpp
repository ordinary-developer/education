class Point {
    public:
        constexpr Point(double xValue = 0, double yValue = 0) noexcept
            : x(xValue), y(yValue) { }
            
        constexpr auto xValue() const noexcept { return x; }
        constexpr auto yValue() const noexcept { return y; }
        
        constexpr void setX(double newX) noexcept {
            x = newX;
        }
        constexpr void setY(double newY) noexcept {
            y = newY;
        }
        
    private:
        double x, y;
};

constexpr Point midpoint(const Point& p1, const Point& p2) noexcept {
  return { (p1.xValue() + p2.xValue()) / 2,
           (p1.yValue() + p2.yValue()) / 2 };
}

constexpr Point reflection(const Point& p) noexcept {
	Point result;
	
	result.setX(-p.xValue());
	result.setY(-p.yValue());
	
	return result;
}

int main() {
	constexpr Point p1(9.4, 27.7);
	constexpr Point p2(28.8, 5.3);
	
	constexpr auto mid = midpoint(p1, p2);
	
	constexpr auto result = reflection(mid);
 	return 0;
}

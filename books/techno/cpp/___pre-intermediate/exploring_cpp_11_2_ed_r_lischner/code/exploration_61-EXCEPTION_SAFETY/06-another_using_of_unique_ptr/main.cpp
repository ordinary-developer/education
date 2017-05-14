#include <iostream>
#include <memory>

class mystery {
    public:
        mystery() = default;
        mystery(mystery const&) { throw "oops"; }
};

class demo {
    public:
        demo(std::unique_ptr<int> x, mystery m, std::unique_ptr<int> y)
            : x_{ std::move(x) }, m_{m}, y_{ std::move(y) } { }

        demo(demo const&) = delete;
        demo& operator=(demo const&) = delete;

        int x() const { return *x_; }
        int y() const { return *y_; }

    private:
        std::unique_ptr<int> x_;
        mystery m_;
        std::unique_ptr<int> y_;
};


int main() { 
    demo d{ std::unique_ptr<int>{ new int{42} }, 
            mystery{}, 
            std::unique_ptr<int>{ new int{24} } };
    std::cout << d.x() << d.y() << '\n';

    return 0;
}

#include <iostream>

struct demo {
    demo() 
        : demo{0} { std::cout << "default constructor" << std::endl; }

    demo(int x) : x_{ x } { std::cout << "constructor(" << x 
                                      << ")\n"; }

    demo(demo const& that)
        : x_{ that.x_ }
    {
        std::cout << "copy constructor(" << x_ << ")\n";
    }

    int x_;
};

demo addone(demo d) {
    ++d.x_;
    return d;
}

int main() {
    demo d1{};
    std::cout << "---------" << std::endl;

    demo d2{ d1 };
    std::cout << "---------" << std::endl;

    demo d3{ 42 };
    std::cout << "---------" << std::endl;

    demo d4{ addone(d3) };

    return 0;
}

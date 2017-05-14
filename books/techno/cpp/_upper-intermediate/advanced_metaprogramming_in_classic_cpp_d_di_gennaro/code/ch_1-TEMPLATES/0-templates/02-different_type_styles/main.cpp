#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class sq1 {
    public:
        sq1(double x) : _s(x * x) { }
        operator double() const { return _s; }

    private:
        double _s;
};

class sq_t {
    public:
        typedef double value_type;

        value_type operator() (double x) const 
        {
            return x * x;
        }
};
const sq_t sq2 = sq_t();

template <typename T> void f(T x) { }

int main() {
    double x1 = sq1(3.14);
    double x2 = sq2(3.14);
    std::cout << x1 << std::endl;
    std::cout << x2 << std::endl;

    f(cos(3.14)); // will be f<double>
    f(sq1(3.14)); // will be f<sq1>
    f(sq2(3.14)); // will be f<sq_t>


    std::vector<double> v1 = { 1, 2, 3 };
    // will not be compiled
    // std::transform(v1.begin(), v1.end(), v1.begin(), sq1);
    //
    std::vector<double> v2 = { 1, 2, 3 };
    std::transform(std::begin(v2), 
                   std::begin(v2), 
                   std::begin(v2), 
                   sq2);

    double a = 1, b = 5, c = 1;
    double y0 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double y1 = (-b + sqrt(sq1(b) - 4 * a * c)) / (2 * a);
    double y2 = (-b + sqrt(sq2(b) - 4 * a * c)) / (2 * a);
    std::cout << y0 << std::endl;
    std::cout << y1 << std::endl;
    std::cout << y2 << std::endl;

    return 0;
}

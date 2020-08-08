#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define sq1(x) ((x) * (x))

double sq2(double x) { return x * x; }

template <typename scalar_t>
inline scalar_t sq3(const scalar_t& x)
{ 
    return x * x; 
}


template <typename T> void f(T x) { }

int main() {
    double x1 = sq1(3.14);
    std::cout << x1 << std::endl;
    double x2 = sq2(3.14);
    std::cout << x2 << std::endl;
    double x3 = sq3(3.14);
    std::cout << x3 << std::endl;

    f(cos(3.14)); // will be f<double>
    f(sq1(3.14)); // apparently will be f<double>
    f(sq2(3.14)); // apparently will be f<double>
    f(sq3(3.14)); // apparently will be f<double>


    std::vector<double> v1 = { 1, 2, 3 };
    // will not be compiled
    // std::transform(v1.begin(), v1.end(), v1.begin(), sq1);
    
    std::vector<double> v2 = { 1, 2, 3 };
    std::transform(std::begin(v2), 
                   std::end(v2),
                   std::begin(v2),
                   sq2);

    std::vector<double> v3 = { 1, 2, 3 };
    // will no be compiled
    // std::transform(v3.begin(), v3.end(), v3.begin(), sq3);
    std::transform(std::begin(v3),
                   std::end(v3),
                   std::begin(v3),
                   sq3<double>);

    double a = 1, b = 5, c = 1;
    double y0 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double y1 = (-b + sqrt(sq1(b) - 4 * a * c)) / (2 * a);
    double y2 = (-b + sqrt(sq2(b) - 4 * a * c)) / (2 * a);
    double y3 = (-b + sqrt(sq3(b) - 4 * a * c)) / (2 * a);
    std::cout << y0 << std::endl;
    std::cout << y1 << std::endl;
    std::cout << y2 << std::endl;
    std::cout << y3 << std::endl;

    return 0;
}

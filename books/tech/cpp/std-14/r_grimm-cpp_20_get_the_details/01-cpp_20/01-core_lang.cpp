#include <cassert>
namespace example_01 { // -> three-way comparison operator
struct MyInt {
    int value;
    MyInt(int value) : value{value} {}
    auto operator <=>(const MyInt &) const = default;
};

void run() {
    MyInt a{1}, b{1}, c{2};
    assert(a == b and a != c);
} }


#include <compare>
#include <iostream>
#include <cassert>
namespace example_02 { // -> designated initialization

void run() {
    {
        struct Basics {
            int i;
            char c;
            float f;
            double d;
            auto operator <=> (const Basics &) const = default;
        };
        
        struct Arrays {
            int ai[1];
            char ac[2];
            float af[3];
            double ad[2][2];
            auto operator <=> (const Arrays &) const = default;
        };
        
        struct Bases : Basics, Arrays {
            auto operator <=>(const Bases &) const = default;
        };
        
        constexpr Bases a  = { { 0, 'c', 1.f, 1.},
            { {1}, { 'a', 'b' }, { 1.f, 2.f, 3.f }, { { 1., 2. }, { 3., 4. }}}};
        constexpr Bases b = a;
        
        static_assert(a == b);
        static_assert(not (a != b));
        static_assert(not (a < b));
        static_assert(a <= b);
        static_assert(not (a > b));
        static_assert(a >= b);
    }

    {
        struct Point2D {
            int x;
            int y;
        };

        class Point3D {
        public:
            int x;
            int y;
            int z;
        };

        Point2D point2D{1, 2};
        Point3D point3D{1, 2, 3};
        std::cout << "point2D: " << point2D.x << " " << point2D.y << std::endl;
        std::cout << "point3D: " << point3D.x << " " << point3D.y << " " << point3D.z << std::endl;
    }

    {
        struct Point2D {
            int x;
            int y;
        };

        class Point3D {
        public:
            int x;
            int y;
            int z;
        };

        Point2D point2D{.x = 1, .y = 2};
        Point3D point3D{.x = 1, .y = 2, .z = 3};
        std::cout << "point2D: " << point2D.x << " " << point2D.y << std::endl;
        std::cout << "point3D: " << point3D.x << " " << point3D.y << " " << point3D.z << std::endl;
    }
} }


#include <cassert>
namespace example_03 { // -> consteval and constinit

consteval int sqr(int n) { return n * n; }
void run() {
    constexpr int r = sqr(100);
    static_assert(10000 == r);
} }


#include <iostream>
#include <cassert>
namespace example_04 {

struct Implicit {
    template <typename T>
    Implicit(T t) {
        std::cout << t << std::endl;
    }
};

struct Explicit {
    template <typename T>
    explicit Explicit(T t) {
        std::cout << t << std::endl;
    }
};

void run() {
    Explicit exp("explicit");
} }


#include <iostream>
#include <vector>
namespace example_05 {

void run() {
    auto foo = []<typename T>(std::vector<T> const & vec) { std::cout << "lambda" << std::endl; };
    foo(std::vector<int>{1, 2, 3});
} }


#include <iostream>
#include <vector>
#include <cmath>
namespace example_06 {
void run() {
    const std::vector<double> v{ 1., -2., 3.};
    double sum  = 0.; 
    for (std::size_t i{0}; i < v.size(); ++i) {
        if (v[i] < 0)
            [[likely]] sum -= sqrt(-v[i]);
        else 
            sum += sqrt(v[i]);
    }
    std::cout << sum << std::endl;
} }


#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl;
    
    std::cout << "example 02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl;
    
    std::cout << "example 03 => [ok]" << std::endl;
    example_03::run();
    std::cout << std::endl;
    
    std::cout << "example 04 => [ok]" << std::endl;
    example_04::run();
    std::cout << std::endl;
    
    std::cout << "example 05 => [ok]" << std::endl;
    example_05::run();
    std::cout << std::endl;
    
    std::cout << "example 06 => [ok]" << std::endl;
    example_06::run();
    std::cout << std::endl;
}
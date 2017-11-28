// common utility functions
#include <random>
std::default_random_engine& global_urng() {
    static std::default_random_engine u{};
    return u;
}

void randomize() {
    static std::random_device rd{};
    global_urng().seed(rd());
}

int pick(int from, int thru) {
    static std::uniform_int_distribution<> d{};
    using parm_t = decltype(d)::param_type;
    return d(global_urng(), parm_t{ from, thru });
}

double pick(double from, double upto) {
    static std::uniform_real_distribution<> d{};
    using parm_t = decltype(d)::param_type;
    return d(global_urng(), parm_t{ from, upto });
}

#include <complex>
namespace example01 {
void run() {
    std::complex<double> z(3, 5), c = static_cast<double>(2) * z;
}
} // namespace example01

#include <complex>
namespace example02 {

template <typename T>
std::complex<T> twice(std::complex<T> const& z) { return T{2} * z; }

void run() {
    std::complex<double> z{3, 5}, c;
    c = twice(z);
}
} // namespace example02

#include <random>
#include <iostream>
namespace example03 {

void run() {
    randomize();
    std::cout << "Now, we roll dice:\n";
    for (int i{0}; i < 15; ++i)
        std::cout << pick(1, 6) << std::endl;

    std::cout << "\nLet's roll continuos dice now: ;-)\n";
    for (int i{0}; i < 15; ++i)
        std::cout << pick(1.0, 6.0) << std::endl;
}
} // namespace example03

#include <limits>
#include <iostream>
#include "complex.hpp"
namespace example04 {

double const eps{ 10 * std::numeric_limits<double>::epsilon() }; 

inline bool similar(complex x, complex y) {
    double sum{ abs(x) + abs(y) };
    if (sum < 1000 * std::numeric_limits<double>::min())
        return true;
    return abs(x - y) / sum <= eps;
}

struct distributivity_violated {};

inline void test(complex a, complex b, complex c) {
    if (not similar(a * (b + c), a * b + a * c)) 
        std::cout << "distribution viloation was detected" << std::endl;
}

const double from = -10.0, upto = 10.0;

inline complex mypick() {
    return complex(pick(from, upto), pick(from, upto));
}

void run() {
    const int max_test{20};
    randomize();

    for (int i{0}; i < max_test; ++i) {
        complex a{ mypick() };
        for (int j{0}; j < max_test; ++j) {
            complex b{ mypick() };
            for (int k{0}; k < max_test; ++k) {
                complex c{ mypick() };
                test(a, b, c);
            }
        }
    }
}
} // namespace example04

#include <random>
#include <iostream>
namespace example05 {

void random_numbers() {
    std::default_random_engine re{};
    std::cout << "Random numbers: ";
    for (int i{0}; i < 4; ++i)
        std::cout << re() << (i < 3 ? ", " : "");
    std::cout << '\n';
}

void run() {
    random_numbers();
    random_numbers();
}
} // namespace example05

#include <random>
#include <iostream>
namespace example06 {

void random_numbers() {
    static std::default_random_engine re{};
    std::cout << "Random numbers: ";
    for (int i{0}; i < 4; ++i)
        std::cout << re() << (i < 3 ? ", " : "");
    std::cout << '\n';
}

void run() {
    random_numbers();
    random_numbers();
}
} // namespace example06

#include <random>
#include <iostream>
namespace example07 {

void random_numbers() {
    static std::random_device rd{};
    static std::default_random_engine re{ rd() };
    std::cout << "Random numbers: ";
    for (int i{0}; i < 4; ++i)
        std::cout << re() << (i < 3 ? ", " : "");
    std::cout << '\n';
} 

void run() {
    random_numbers();
    random_numbers();
}
} // namespace example07

#include <functional>
#include <random>
#include <iostream>
namespace example08 {
void run() {
    std::default_random_engine re{ std::random_device{}() };
    std::normal_distribution<> normal1{};

    for (int i{0}; i < 6; ++i)
        std::cout << normal1(re) << std::endl;

    auto normal2 = 
        std::bind(std::normal_distribution<>{},
                  std::default_random_engine{ std::random_device{}() });
    for (int i{0}; i < 6; ++i)
        std::cout << normal2() << std::endl;

    auto normal3 = [re = std::default_random_engine{std::random_device{}()},
                   n = std::normal_distribution<>{}]
                  () mutable
                  {
                      return n(re);
                  };
    for (int i{0}; i < 6; ++i)
        std::cout << normal3() << std::endl;
}
} // namespace example08

#include <random>
#include <vector>
#include <cmath>
#include <iostream>
namespace example09 {
void run() {
    std::default_random_engine re{ std::random_device{}() };
    std::normal_distribution<> normal{};

    double const mu{0.05}, sigma{0.3}, delta{0.5}, year{20.01};
    double const a{ sigma * sqrt(delta) };
    double const b{ delta * (mu - 0.5 * sigma * sigma) };

    std::vector<double> s{ 345.2 };

    for (double t{0.0}; t < year; t += delta)
        s.push_back(s.back() * exp(a * normal(re) + b));

    for (auto const& element : s)
        std::cout << element << std::endl;
}
} // namespace example09


int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();
    example06::run();
    example07::run();
    example08::run();
    example09::run();

    return 0;
}

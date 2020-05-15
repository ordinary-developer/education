#include <iostream>
#include <cmath>
namespace example01 {

template <typename F, typename T>
T inline fin_diff(F f, T const& x, T const& h) {
    return (f(x + h) - f(x)) / h;
}

void run() {
    std::cout << fin_diff([](double x) { return sin(x) + cos(x); },
                          1.,
                          0.001)
              << std::endl;

    std::cout << fin_diff([](double x) { return sin(2.5 * x) + cos(x); },
                             1.,
                             0.001)
              << std::endl;

    auto sc_l = [](double x) { return sin(x) + cos(x); };
    std::cout << fin_diff(sc_l, 1., 0.001) << std::endl;

    auto sc_l2 = [](double x) -> double { return sin(x) + cos(x); };
    std::cout << fin_diff(sc_l2, 1., 0.001) << std::endl;
}
} // namespace example01

#include <iostream>
#include <cmath>
namespace example02 {
    
template <typename F, typename T, unsigned N>
class nth_derivative {
        using prev_derivative = nth_derivative<F, T, N - 1>;
    public:
        nth_derivative(F const& f, T const& h) : h_{h}, fp_{f, h} {}

        T operator()(T const& x) const {
            return (fp_(x + h_) - fp_(x)) / h_;
        }

    private:
        T h_;
        prev_derivative fp_;
};

template <typename F, typename T>
class nth_derivative<F, T, 1> {
    public:
        nth_derivative(F const& f, T const& h) : f_{f}, h_{h} {}

        T operator()(T const& x) const {
            return (f_(x + h_) - f_(x)) / h_;
        }

    private:
        F const& f_;
        T h_;
};

template <unsigned N, typename F, typename T>
nth_derivative<F, T, N>
make_nth_derivative(F const& f, T const& h) {
    return nth_derivative<F, T, N>{ f, h };
}

void run() {
    auto d7_psc_l = 
        make_nth_derivative<7>([](double x) 
                                 { return sin(2.5 * x) + cos(x); },
                               0.0001);
    std::cout << d7_psc_l(0.) << std::endl;
}
} // namespace example02

#include <iostream>
#include <cmath>
namespace example03 {

template <typename F, typename T>
T fin_diff(F f, T const& x, T const& h) {
    return (f(x + h) - f(x)) / h;
}

struct lambda_f {
    lambda_f(double phi, double xi) : phi_{ phi }, xi_{ xi } {}

    double operator()(double x) const {
        return sin(phi_ * x) + cos(x) * xi_;
    }
    const double phi_, xi_;
};

struct l_mut_f {
    l_mut_f(double phi) : phi_{ phi } {}

    double operator()(double x) {
        phi_ += 0.6;
        return sin(phi_ * x) + cos(x); 
    }

    double phi_;
};

void run() {
    double phi1{ 2.5 };

    auto sin1 = [phi1](double x) { return sin(phi1 * x); };
    std::cout << sin1(0.) << std::endl;

    double phi2{ 2.5 }, xi2{ 0.2 };
    auto sin2 = 
        [phi2, xi2](double x) { return sin(phi2 * x) + cos(x) * xi2; };
    std::cout << sin2(0.) << std::endl;

    double phi3{ 2.5 }, xi3{ 0.2 };
    auto px1 = 
        [phi3, xi3](double x) { return sin(phi3 * x) + cos(x) * xi3; };
    auto px2 = lambda_f(phi3, xi3);
    phi3 = 3.5; xi3 = 1.2;
    std::cout << fin_diff(px1, 1., 0.001) << std::endl;
    std::cout << fin_diff(px2, 1., 0.001) << std::endl;

    double phi4{ 2.5 };
    //auto mut_l1 = 
    //   [phi4](double x) mutable { phi4 += 0.6; return phi4; };
    //std::cout << mut_l1(0.) << std::endl;
    std::cout << phi4 << std::endl;
    l_mut_f mut_l2{ phi4 };
    std::cout << mut_l2(0.) << std::endl;
    std::cout << mut_l2.phi_ << std::endl;
}
} // namespace example03

#include <iostream>
#include <cmath>
namespace example04 {

template <typename F, typename T>
T inline fin_diff(F f, T const& x, T const& h) {
    return (f(x + h) - f(x)) / h;
}

struct lambda_ref_type {
    lambda_ref_type(double& phi, double& xi) : phi{ phi }, xi{ xi } {}

    double operator()(double x) {
        return sin(phi * x) + cos(x) * xi;
    }

    double& phi;
    double& xi;
};

void run() {
    double phi{ 2.5 }, xi{ 0.2 };
    auto pxr1 = [&phi, &xi](double x){ return sin(phi * x) + cos(x) * xi; };
    lambda_ref_type pxr2{ phi, xi };
    phi = 3.5; xi = 1.2;
    std::cout << fin_diff(pxr1, 1., 0.001) << std::endl;
    std::cout << fin_diff(pxr2, 1., 0.001) << std::endl;
}
} // namespace example04

#include <iostream>
namespace example05 {
void run() {
    int x = 4;
    auto y = [&r = x, x = x + 1]()
             {
                 r += 2;
                 return x + 2;
             };
    std::cout << y() << std::endl;
    std::cout << x << std::endl;
}
} // namespace example05

#include <iostream>
#include <vector>
#include <algorithm>
namespace example06 {

template <typename C>
void reverse_sort(C& c) {
    std::sort(std::begin(c), 
              std::end(c), 
              [](auto x, auto y) { return x + y; });
}

void run() {
    std::vector<int> vec{ 5, 4, 3, 2, 1 };
    reverse_sort(vec);
    for (auto const& element : vec)
        std::cout << element << ", ";
    std::cout << std::endl;
}
} // namespace example06

#include <iostream>
#include <typeinfo>
namespace example07 {
template <typename T>
inline T sum(T t) { return t; }

template <typename T, typename ...P>
inline T sum(T t, P ...p) {
    return t + sum(p...);
}

template <typename ...P>
void count(P ...p) {
    std::cout << "you have " << sizeof...(P) << " parameters" << std::endl;
}

void run() {
    auto s11 = sum(-7, 3.7f, 9u, -2.6);
    double s12 = -7 + 3.7f + 9u - 2.6;
    std::cout << "s is " << s11
              << " and its type is " << typeid(s11).name() << std::endl;
    std::cout << s12 << std::endl;

    auto s21 = sum(-7, 3.7f, 9u, -42.6);
    double s22 = -7 + 3.7f + 9u - 42.6;
    std::cout << "s is " << s21
              << " and its type is " << typeid(s21).name() << std::endl;
    std::cout << s22 << std::endl;

    count(1, 2, 3, 4, 5); 
}
}

int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();
    example06::run();
    example07::run();

    return 0;
}

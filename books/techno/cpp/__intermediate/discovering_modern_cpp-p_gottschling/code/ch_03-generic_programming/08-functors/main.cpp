#include <cmath>
#include <iostream>
namespace example01 {

double fin_diff(double f(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
}

double sin_plus_cos(double x) {
    return sin(x) + cos(x);
}

void run() { 
    std::cout << fin_diff(sin_plus_cos, 1., 0.001) << std::endl;
    std::cout << fin_diff(sin_plus_cos, 0., 0.001) << std::endl;
}

} // namespace example01

#include <cmath>
#include <iostream>
namespace example02 {

struct sc_f {
    double operator() (double x) const { return sin(x) + cos(x); }
};

class psc_f {
    public:
        psc_f(double alpha) : alpha_{alpha} {}
        double operator() (double x) const { 
            return sin(alpha_ * x) + cos(x);
        }

    private:
        double alpha_;
};

double sin_plus_cos(double x) {
    return sin(x) + cos(x);
}

template <typename F, typename T>
T inline fin_diff(F f, T const& x, T const& h) {
    return (f(x + h) - f(x)) / h;
}

void run() {
    std::cout << sc_f{}(5.) << std::endl;
    std::cout << psc_f{0.5}(5.) << std::endl;

    psc_f psc_o{ 1.0 };
    std::cout << fin_diff(psc_o, 1., 0.001) << std::endl;
    std::cout << fin_diff(psc_f{2.0}, 1., 0.001) << std::endl;
    std::cout << fin_diff(sin_plus_cos, 0., 0.001) << std::endl;
}

} // namespace example02

namespace example03 {

template <typename F, typename T>
class derivative {
    public:
        derivative(F const& f, T const& h) : f_{f}, h_{h} { }
        T operator() (T const& x) const {
            return (f_(x + h_) - f_(x)) / h_;
        }
        
    private:
        const F& f_;
        T h_;
};

class psc_f {
    public:
        psc_f(double alpha) : alpha_{alpha} {}
        double operator() (double x) const { 
            return sin(alpha_ * x) + cos(x);
        }

    private:
        double alpha_;
};

template <typename F, typename T>
class second_derivative {
    public:
        second_derivative(F const& f, T const& h) : h_{h}, fp_{f, h} {}
        T operator() (T const& x) const {
            return (fp_(x + h_) - fp_(x)) / h_;
        }
    private:
        T h_;
        derivative<F, T> fp_;
};
    
void run() {
    using d_psc_f = derivative<psc_f, double>;
    using dd_psc_f = derivative<d_psc_f, double>;

    psc_f psc_o{1.0};
    d_psc_f d_psc_o{ psc_o, 0.001 };
    dd_psc_f dd_psc_o{ d_psc_o, 0.001 };
    second_derivative<psc_f, double> dd_psc_2_o{ psc_f{1.0}, 0.001 };

    std::cout << "1 st der. of sin(0) + cos(0) is " 
              << d_psc_o(0.0) << '\n';
    std::cout << "2 nd der. of sin(0) + cos(0) is "
              << dd_psc_o(0.0) << '\n';
}

} // namespace example03

#include <iostream>
#include <cmath>
namespace example04 {

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

class psc_f {
    public:
        psc_f(double alpha) : alpha_{alpha} {}
        double operator() (double x) const { 
            return sin(alpha_ * x) + cos(x);
        }

    private:
        double alpha_;
};

void run() {
    nth_derivative<psc_f, double, 22> d22_psc_o{ psc_f{1.0}, 0.00001 };
    std::cout << d22_psc_o(0.0) << std::endl;
}

} // namespace example04

#include <iostream>
#include <cmath>
namespace example05 {

template <typename F, typename T>
class derivative {
    public:
        derivative(F const& f, T const& h) : f_{f}, h_{h} { }
        T operator() (T const& x) const {
            return (f_(x + h_) - f_(x)) / h_;
        }
        
    private:
        const F& f_;
        T h_;
};

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
class nth_derivative<F, T, 1> : public derivative<F, T> {
    using derivative<F, T>::derivative;
};
    

class psc_f {
    public:
        psc_f(double alpha) : alpha_{alpha} {}
        double operator() (double x) const { 
            return sin(alpha_ * x) + cos(x);
        }

    private:
        double alpha_;
};

void run() {
    nth_derivative<psc_f, double, 22> d22_psc_o{ psc_f{1.0}, 0.00001 };
    std::cout << d22_psc_o(0.0) << std::endl;
}

} // namespace example05

#include <iostream>
#include <cmath>
namespace example06 {

template <typename F, typename T, unsigned N>
class nth_derivative {
        using prev_derivative = nth_derivative<F, T, N - 1>;
    public:
        nth_derivative(F const& f, T const& h) : h_{h}, fp_{ f, h } {}

        T operator() (T const& x) const {
            return N & 1 ? (fp_(x + h_) - fp_(x)) / h_
                         : (fp_(x) - fp_(x - h_)) / h_;
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

class psc_f {
    public:
        psc_f(double alpha) : alpha_{alpha} {}
        double operator() (double x) const { 
            return sin(alpha_ * x) + cos(x);
        }

    private:
        double alpha_;
};

void run() {
    nth_derivative<psc_f, double, 22> d22_psc_o{ psc_f{1.0}, 0.00001 };
    std::cout << d22_psc_o(0.0) << std::endl;
}
} // namespace example06

namespace example07 {

template <typename F, typename T, unsigned N>
class nth_derivative {
        using prev_derivative = nth_derivative<F, T, N - 1>;
    public:
        nth_derivative(F const& f, T const& h) : h_{h}, fp_{ f, h } {}

        T operator() (T const& x) const {
            return N & 1 ? (fp_(x + h_) - fp_(x)) / h_
                         : (fp_(x) - fp_(x - h_)) / h_;
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

class psc_f {
    public:
        psc_f(double alpha) : alpha_{alpha} {}
        double operator() (double x) const { 
            return sin(alpha_ * x) + cos(x);
        }

    private:
        double alpha_;
};

template <unsigned N, typename F, typename T>
nth_derivative<F, T, N>
make_nth_derivative(F const& f, T const& h) {
    return nth_derivative<F, T, N>{ f, h };
}

void run() {
    psc_f psc_o{1.0};
    auto d7_psc_o = make_nth_derivative<7>(psc_o, 0.00001);
    std::cout << d7_psc_o(0.0) << std::endl;
}

} // namespace example07

#include <vector>
#include <iostream>
namespace example08 {

template <typename Iter, typename T, typename BinaryFunction>
T accumulate(Iter it, Iter end, T init, BinaryFunction op) {
    for (; it != end; ++it)
        init = op(init, *it);
    return init;
}

template <typename T>
struct add {
    T operator()(T const& x, T const& y) const { return x + y; }
};

struct times {
    template <typename T>
    T operator()(T const& x, T const& y) const { return x * y; }
};

void run() {
    std::vector<double> v = {7.0, 8.0, 11.0};

    double s = accumulate(v.begin(), v.end(), 0.0, add<double>{});
    std::cout << s << std::endl;

    double p = accumulate(v.begin(), v.end(), 1.0, times{});
    std::cout << p << std::endl;
}

} // namepsace example08

int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();
    example06::run();
    example07::run();
    example08::run();

    return 0;
}



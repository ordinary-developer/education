#include <cmath>
namespace example01 {

int g(int x, int y, int z) { return x + y + z; }

void run() {
    int x{1}, y{2}, z{3};

    auto i = 2 * 7.5, j = std::sqrt(3.7);
    auto v = g(x, y, z);

    auto& ri = i;
    auto const& cri = i;
    auto&& ur = g(x, y, z); 
}

} // namespace example01

#include <iostream>
#include <vector>
namespace example02 {

struct too_small{};
struct too_large{};

template <typename Vector>
class value_range_vector {
        using value_type = typename Vector::value_type;
        using size_type = typename Vector::size_type;
    public:
        value_range_vector(Vector& vref, value_type minv, value_type maxv)
            : vref_{vref}, minv_{minv}, maxv_{maxv} { }

        decltype(auto) operator[](size_type i) {
            decltype(auto) value = vref_[i];
            if (value < minv_)
                throw too_small{};
            if (value > maxv_)
                throw too_large();
            return value;
        }

    private:
        Vector& vref_;
        value_type minv_, maxv_;
};

void run() {
    using Vector = std::vector<double>;
    Vector v = {2.3, 8.1, 9.2};

    value_range_vector<Vector> w(v, 1.0, 10.0);
    decltype(auto) val = w[1];
    std::cout << "value is: " << val << std::endl;
}
} // namespace example02

#include <iostream>
#include <typeinfo>
namespace example03 {

typedef double value_type1;
using value_type2 = double;

typedef double da1[10];
using da2 = double[10];

typedef float float_fun1(float, int);
using  float_fun2 = float(float, int);

template <unsigned Order, typename Value>
class tensor {};

template <typename Value>
using vector = tensor<1, Value>;

template <typename Value>
using matrix = tensor<2, Value>;

void run() {
    value_type1 var1{};
    value_type2 var2{};

    da1 var3{};
    da2 var4{};

    float_fun1 var5;
    float_fun2 var6;

    std::cout << "type of vector<float> is "
              << typeid(vector<float>).name() << '\n';
    std::cout << "type of matrix<float> is "
              << typeid(matrix<float>).name() << '\n';
}
} //namespace example03

int main() {
    example01::run();
    example02::run();
    example03::run();

    return 0;
}

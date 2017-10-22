#include <memory>
#include <iostream>
namespace example01 {

template <typename T>
class vector {};

class vector_bool_proxy {
    public:
        vector_bool_proxy(unsigned char& byte, int p)
            : byte_{ byte }, mask_{ static_cast<unsigned char>(1 << p) } {}

        operator bool() const { return byte_ & mask_; }

        vector_bool_proxy& operator= (bool b) {
            if (b)
                byte_ |= mask_;
            else
                byte_ &= ~mask_;

            return *this;
        }
    private:
        unsigned char& byte_;
        unsigned char mask_;
};

template <>
class vector<bool> {
    public:
        explicit vector(int size)
            : size_{ size }, data_{ new unsigned char[(size_ + 7) / 8] } {}
        vector() :size_{ 0 } {}

        bool operator[](int i) const 
        { return (data_[i / 8] >> i % 8) & 1; }

        vector_bool_proxy operator[](int i) 
        { return { data_[i / 8], i % 8 }; }

    private:
        int size_;
        std::unique_ptr<unsigned char[]> data_;
};

void run() { 
    vector<bool> b(13);
    for (int i{0}; i < 13; ++i)
        b[i] = i & 1;
    for (int i{0}; i < 13; ++i)
        std::cout << b[i] << std::endl;
    std::cout << std::endl;
}
} // namespace example01

#include <complex>
#include <cmath>
#include <iostream>
namespace example02 {

template <typename T>
struct abs_functor
{
    using result_type = T;

    T operator()(T const& x) { return x < T{0} ? -x : x; }
};

template <typename T>
struct abs_functor<std::complex<T>> {
    typedef T result_type;
    T operator()(std::complex<T> const& x) {
        return std::sqrt(std::real(x) * std::real(x) + 
                         std::imag(x) * std::imag(x));
    }
};

// C++14
template <typename T>
decltype(auto) abs1(T const& x) { return abs_functor<T>{}(x); }

// C++11
template <typename T>
auto abs2(T const& x) -> decltype(abs_functor<T>{}(x)) {
    return abs_functor<T>{}(x);
}

// C++03
template <typename T>
typename abs_functor<T>::result_type
abs3(const T& x) {
    return abs_functor<T>()(x);
}

void run() {
    int a{5};
    double b{5.};
    std::complex<double> c{5.0, 5.0}; 

    std::cout << "abs1(a) => " << abs1(a) << std::endl;
    std::cout << "abs1(b) => " << abs1(b) << std::endl;
    std::cout << "abs1(c) => " << abs1(c) << std::endl;

    std::cout << "abs2(a) => " << abs2(a) << std::endl;
    std::cout << "abs2(b) => " << abs2(b) << std::endl;
    std::cout << "abs2(c) => " << abs2(c) << std::endl;

    std::cout << "abs3(a) => " << abs3(a) << std::endl;
    std::cout << "abs3(b) => " << abs3(b) << std::endl;
    std::cout << "abs3(c) => " << abs3(c) << std::endl;
}

} // example02

int main() {
    example01::run();
    example02::run();

    return 0;
}

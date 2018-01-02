// using auto for different types
#include <iostream>
#include <cmath>
#include <complex>
namespace example01 {

template <typename T>
T inline min_magnitude(T const& x, T const& y) {
    auto ax = std::abs(x), ay = std::abs(y);
    return ax < ay ? x : y;
}

void run() {
    double d1{3.}, d2{4.};
    std::cout << "min |d1, d2| = " << min_magnitude(d1, d2) << '\n';

    std::complex<double> c1{3.}, c2{4.};
    std::cout << "min |c1, c2| = " << min_magnitude(c1, c2) << '\n';
}
} // namespace example01

// using type info for different types
#include <iostream>
#include <cmath>
#include <complex>
namespace example02 {

#if 0
template <typename T>
struct Magnitude {};

template <>
struct Magnitude<int> {
    using type = int;
};

template <>
struct Magnitude<float> {
    using type = float;
};

template <>
struct Magnitude<double> {
    using type = double;
};

template <>
struct Magnitude<std::complex<float>> {
    using type = float;
};

template <>
struct Magnitude<std::complex<double>> {
    using type = double;
};
#endif

template <typename T>
struct Magnitude {
    using type = T;
};

template <typename T>
struct Magnitude<std::complex<T>> {
    using type = T;
};

template <typename T>
T inline min_magnitude(T const& x, T const& y) {
    typename Magnitude<T>::type ax{ std::abs(x) }, ay{ std::abs(y) };
    return ax < ay ? x : y;
}

void run() {
    double d1{3.}, d2{4.};
    std::cout << "min |d1, d2| = " << min_magnitude(d1, d2) << '\n';

    std::complex<double> c1{3.}, c2{4.};
    std::cout << "min |c1, c2| = " << min_magnitude(c1, c2) << '\n';
}
} // namespace example02

// using is_nothrow_copy_constructible
#include <type_traits>
#include <iostream>
namespace example03 {

template <typename T>
inline T clone(T const& x) 
    noexcept(std::is_nothrow_copy_constructible<T>::value)
{
    return T{x};
}

void run() {
    int i{3};
    int j{ clone(i) };
    j++;
    std::cout << "j value is -> " << j << std::endl;
    std::cout << "i value is -> " << i << std::endl;
}
} // namespace example03

// a const-clean view example
#include <vector>
#include <initializer_list>
#include <cstdlib>
#include <iostream>
#include <typeinfo>
namespace example04 {

template <typename Matrix>
class transposed_view {
    public:
        using value_type = typename Matrix::value_type;
        using size_type = typename Matrix::size_type;

        explicit transposed_view(Matrix& A) : ref(A) { }

        value_type& operator()(size_type r, size_type c) 
        { return ref(c, r); }
        value_type const& operator()(size_type r, size_type c) const
        { return ref(c, r); }

    private:
        Matrix& ref;
};

template <typename T>
class dense2D {
    public:
        using value_type = T;
        using size_type = size_t;

        dense2D(std::initializer_list<std::vector<T>> const& src)
            : contents_(src) {}

        value_type& operator()(size_type r, size_type c) {
            return contents_[c][r];
        }

        value_type const& operator()(size_type r, size_type c) const {
            return contents_[c][r];
        }

    private:
        std::vector<std::vector<T>> contents_;
};

template <typename Matrix>
inline transposed_view<Matrix> trans(Matrix& A) {
    return transposed_view<Matrix>(A);
}

void run() {
    dense2D<float> A{ {2, 3, 4}, 
                      {5, 6, 7},
                      {8, 9, 10}};
    transposed_view<dense2D<float>> At(A);
    At(2, 0) = 4.5;
    auto v = trans(A);

    const dense2D<float> B(A);
    std::cout << "trans(A) is " << typeid(trans(A)).name() << std::endl;
    std::cout << "trans(B) is " << typeid(trans(B)).name() << std::endl;
    //int ta = trans(A);
    //int tb = trans(B);
    
    const transposed_view<const dense2D<float>> Bt(B);
    std::cout << "Bt(2, 0) = " << Bt(2, 0) << '\n';
}
} // namespace example04

#include <iostream>
#include <initializer_list>
#include <cstdlib>
// working with const args
namespace example05 {

template <typename T>
class dense2D {
    public:
        using value_type = T;
        using size_type = size_t;

        dense2D(std::initializer_list<std::vector<T>> const& src)
            : contents_(src) {}

        value_type& operator()(size_type r, size_type c) {
            return contents_[c][r];
        }

        value_type const& operator()(size_type r, size_type c) const {
            return contents_[c][r];
        }

    private:
        std::vector<std::vector<T>> contents_;
};

template <typename Matrix>
class const_transposed_view {
    public:
        using value_type = typename Matrix::value_type;
        using size_type = typename Matrix::size_type;

        explicit const_transposed_view(Matrix const& A) : ref(A) {}

        value_type const& operator()(size_type r, size_type c) const {
            return ref(c, r);
        }

    private:
        Matrix const& ref;
};

template <typename Matrix>
inline const_transposed_view<Matrix> trans(Matrix const& A) {
    return const_transposed_view<Matrix>(A);
}

void run() {
    dense2D<float> A{ {2, 3, 4}, 
                      {5, 6, 7},
                      {8, 9, 10}};
    const_transposed_view<dense2D<float>> B{A};
    std::cout << "Bt(2, 0) = " << B(2, 0) << '\n';

    dense2D<float> const A2{A};
    const_transposed_view<dense2D<float>> B2{A2};
    std::cout << "B2(2, 0) = " << B2(2, 0) << '\n';
}
} // namespace example05

// check for constancy
#include <iostream>
#include <type_traits>
#include <cstdlib>
namespace example06 {

template <typename T>
struct is_const {
    static const bool value{false};
};

template <typename T>
struct is_const<T const> {
    static const bool value{true};
};

template <bool Condition, typename ThenType, typename ElseType>
struct conditional {
    using type = ThenType;
};

template <typename ThenType, typename ElseType>
struct conditional<false, ThenType, ElseType> {
    using type = ElseType;
};


template <typename T>
class dense2D {
    public:
        using value_type = T;
        using size_type = size_t;

        dense2D(std::initializer_list<std::vector<T>> const& src)
            : contents_(src) {}

        value_type& operator()(size_type r, size_type c) {
            return contents_[c][r];
        }

        value_type const& operator()(size_type r, size_type c) const {
            return contents_[c][r];
        }

    private:
        std::vector<std::vector<T>> contents_;
};

template <typename Matrix>
class transposed_view {
    public:
        using value_type = typename Matrix::value_type;
        using size_type = typename Matrix::size_type;
        using vref_type = std::conditional_t<is_const<Matrix>::value,
                                             value_type const&,
                                             value_type&>;

        transposed_view(Matrix& A) : ref(A) {}

        vref_type operator()(size_type r, size_type c)
        { return ref(c, r); }

        value_type const& operator()(size_type r, size_type c) const 
        { return ref(c, r); }

    private:
        Matrix& ref;
};

void run() {
    int const max_iter{101};
    using tmp_type =
        typename conditional<(max_iter > 100), double, float>::type;

    dense2D<float> A{ {2, 3, 4}, 
                      {5, 6, 7},
                      {8, 9, 10}};
    transposed_view<dense2D<float>> B{A};
    std::cout << "B(2, 0) = " << B(2, 0) << '\n';

    dense2D<float> const A2{A};
    transposed_view<dense2D<float> const> B2(A2);
    std::cout << "B2(2, 0) = " << B2(2, 0) << '\n';
}

} // namespace example06

// domain specific type properties
#include <type_traits>
#include <assert.h>
namespace example07 {

template <typename T>
struct is_const {
    static const bool value{false};
};

template <typename T>
struct is_const<T const> {
    static const bool value{true};
};

template <typename T>
class dense2D;

template <typename Matrix>
class transposed_view;

template <typename T>
struct is_matrix0 {
    static const bool value{false};
};

template <typename T>
struct is_matrix : std::false_type {};

template <typename T>
struct is_matrix<T const> : is_matrix<T> {};

template <typename T>
struct is_matrix<dense2D<T>> : std::true_type {};

template <typename Matrix>
struct is_matrix<transposed_view<Matrix>> : std::true_type {};

template <typename T>
class dense2D {
    public:
        using value_type = T;
        using size_type = size_t;

        dense2D(std::initializer_list<std::vector<T>> const& src)
            : contents_(src) {}

        value_type& operator()(size_type r, size_type c) {
            return contents_[c][r];
        }

        value_type const& operator()(size_type r, size_type c) const {
            return contents_[c][r];
        }

    private:
        std::vector<std::vector<T>> contents_;
};

template <typename Matrix>
class transposed_view {
    public:
        static_assert(is_matrix<Matrix>::value,
                      "Argument of view must be a matrix!");

        using value_type = typename Matrix::value_type;
        using size_type = typename Matrix::size_type;
        using vref_type = std::conditional_t<is_const<Matrix>::value,
                                             value_type const&,
                                             value_type&>;

        transposed_view(Matrix& A) : ref(A) {}

        vref_type operator()(size_type r, size_type c)
        { return ref(c, r); }

        value_type const& operator()(size_type r, size_type c) const 
        { return ref(c, r); }

    private:
        Matrix& ref;
};


void run() {
    dense2D<float> A{ {2, 3, 4}, 
                      {5, 6, 7},
                      {8, 9, 10}};
    transposed_view<dense2D<float>> B{A};

    dense2D<float> const A2{A};
    transposed_view<dense2D<float> const> B2(A2);
}
} // namespace example07

// enable_if using
#include <iostream>
#include <type_traits>
#include <complex>
#include <cmath>
namespace example08 {

// #region [forward declarations]
template <typename T>
class dense_vector;

template <typename T>
class dense2D;
// #endregion [forward declarations]

template <bool Condition, typename T = void>
struct enable_if {
    using type = T;
};

template <typename T>
struct enable_if<false, T> {};

template <bool Condition, typename T = void>
using enable_if_t = typename enable_if<Condition, T>::type;

template <typename T>
struct Magnitude {
    using type = T;
};

template <typename T>
struct Magnitude<std::complex<T>> {
    using type = T;
};

template <typename T>
struct Magnitude<dense_vector<T>> {
    using type = typename Magnitude<T>::type;
};

template <typename T>
struct Magnitude<dense2D<T>> {
    using type = typename Magnitude<T>::type;
};

template <typename T>
struct is_matrix : std::false_type {};

template <typename T>
struct is_matrix<T const> : is_matrix<T> {};

template <typename T>
struct is_matrix<dense2D<T>> : std::true_type {};

template <typename T>
struct is_vector : std::false_type {};

template <typename T>
struct is_vector<T const> : is_vector<T> {};

template <typename T>
struct is_vector<dense_vector<T>> : std::true_type {};

template <bool B, typename T>
struct enable_if_c {
    using type = T;
};

template <typename T>
struct enable_if_c<false, T> {};

template <typename Condition, typename T>
struct enable_if_ : enable_if_c<Condition::value, T> {};

template <typename T>
typename enable_if_c<is_matrix<T>::value, typename Magnitude<T>::type>::type
inline one_norm(T const& A)
{}

template <typename T>
typename enable_if_<is_vector<T>, typename Magnitude<T>::type>::type
inline one_norm(T const& v)
{}

// #region [class declarations]
template <typename T>
class dense_vector {

};

template <typename T>
class dense2D {
    public:
        using value_type = T;
        using size_type = size_t;

        dense2D(std::initializer_list<std::vector<T>> const& src)
            : contents_(src) {}

        value_type& operator()(size_type r, size_type c) {
            return contents_[c][r];
        }

        value_type const& operator()(size_type r, size_type c) const {
            return contents_[c][r];
        }

        unsigned num_cols() const { return contents_.size(); }

    private:
        std::vector<std::vector<T>> contents_;
};

template <typename T>
unsigned num_cols(dense2D<T> const& matrix) {
    return matrix.num_cols();
}
// #endregion [class declarations]

template <typename T>
using Magnitude_t = typename Magnitude<T>::type;

template <typename T>
enable_if_t<is_matrix<T>::value, Magnitude_t<T>>
inline one_norm(T const& A)
{
    Magnitude_t<T> max{0};
    for (unsigned c{0}; c < num_cols(A); ++c) {
        Magnitude_t<T> sum{0};
        for (unsigned r{0}; r < num_cols(A); ++r) {
            sum += std::abs(A[r][c]);
        }
        max = max < sum ? sum : max;
    }
    return max;
}

void run() {
    dense2D<float> A{ {2, 3, 4}, 
                      {5, 6, 7},
                      {8, 9, 10}};
    auto value = one_norm(A);

}

} // namespace example08

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


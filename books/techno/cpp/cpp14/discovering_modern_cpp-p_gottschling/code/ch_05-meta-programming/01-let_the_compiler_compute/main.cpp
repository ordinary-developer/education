#include <iostream>
#include <cstdlib>
namespace example01 {

constexpr long fibonacci(long n) {
    return n <= 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

constexpr double square_constexpr(double x) {
    return x * x;
}

template <typename T>
constexpr T square_template(T x) {
    return x * x;
}

void run() {
    std::cout << fibonacci(5) << std::endl;
    std::cout << square_constexpr(5.0) << std::endl;
    std::cout << square_template(5.0) << std::endl;
    long n = atoi("7");
    std::cout << "fibonacci(" << n << ") = " << fibonacci(n) << '\n';
}
} // namespace example01

#include <iostream>
namespace example02 {

constexpr void square(int& x) { x *= x; }

template <typename T>
constexpr T power(T const& x, int n) {
    T r{1};
    while (--n > 0)
        r *= x;
    return r;
}

void run() {
    int x = 5;
    square(x);
    std::cout << x << std::endl;

    int y{10}, n{4};
    std::cout << power(y, n) << std::endl;
}
} // namespace example02

#include <iostream>
#include <cstddef>
#include <cassert>
namespace example03 {

constexpr size_t popcount_cycle(size_t x) {
    int count{0};
    for (; x != 0; ++count)
        x &= x - 1;
    return count;
}

constexpr size_t popcount_recursion(size_t x) {
    return 0 == x ? 0 : popcount_recursion(x & x - 1) + 1;
}

void run() {
    constexpr size_t bits1{ popcount_cycle(0x5555) };
    static_assert(8 == popcount_cycle(0x5555), "popcount(0x5555) != 8");

    constexpr size_t bits2{ popcount_recursion(0x5555) };
    static_assert(8 == popcount_recursion(0x5555), "popcount(0x5555) != 8");
}
} // namespace example03

// prime numbers
#include <iostream>
#include <cmath>
namespace example04 {

constexpr int const_abs(int i) {
    return i < 0 ? -i : i;
}

constexpr int square_root(int x) {
    double r{ static_cast<double>(x) }, dx{ static_cast<double>(x) };
    while (const_abs((r * r) - dx) > 0.1) 
        r = (r + dx/r) / 2;
    return static_cast<int>(r);
}

#define version 4

#if version == 1
constexpr bool is_prime(int i) {
    if (1 == i)
        return false;
    if (0 == i % 2)
        return 2 == i;
    for (int j{3}; j < i; j += 2)
        if (0 == i % j)
            return false;
    return true;
}

#elif 2 == version 
constexpr bool is_prime(int i) {
    if (1 == i)
        return false;
    if (0 == i % 2)
        return 2 == i;
    int max_check{ static_cast<int>(sqrt(i)) + 1 };
    for (int j{3}; j < max_check; j += 2)
        if (0 == i % j)
            return false;
    return true;
}

#elif 3 == version
constexpr bool is_prime(int i) {
    if (1 == i)
        return false;
    if (0 == i % 2)
        return 2 == i;
    int max_check{ square_root(i) + 1 };
    for (int j{3}; j < max_check; j += 2)
        if (0 == i % j)
            return false;
    return true;
}

#elif 4 == version
constexpr bool is_prime_aux(int i, int div) {
    return div >= i 
           ? true 
           : ( 0 == i % div ? false : is_prime_aux(i, div + 2));
}

constexpr bool is_prime(int i) {
    return 1 == i 
           ? false
           : (0 == i % 2 ? 2 == i : is_prime_aux(i, 3));
}

#endif

void run() {
    constexpr bool is_17_prime = is_prime(17);
    std::cout << "17 is prime? -> " << is_17_prime << std::endl;

    for (int i{1}; i < 20; ++i)
        std::cout << i << " is " << (is_prime(i) ? "" : "not ") << "prime.\n";
}

} // namespace example04

#include <iostream>
#include <cmath>
namespace example05 {

template <long N>
struct static_long {
    static long const value{ N };
};

void run() {
    const long i{7}, j{8};
    const long k{i + j};
    static_long<k> sk{};

    long const ri{ static_cast<long>(floor(sqrt(i))) };
    static_long<ri> sri{};

    constexpr long ri2{ static_cast<long>(floor(sqrt(i))) };
}
} // namespace example05


int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();

    return 0;
}

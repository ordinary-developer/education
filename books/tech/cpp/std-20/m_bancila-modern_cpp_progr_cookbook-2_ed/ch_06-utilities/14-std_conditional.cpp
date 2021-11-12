#include <algorithm>
#include <random>
#include <string>
#include <type_traits>
#include <vector>

#include <iostream>
namespace example_01 { // -> the "how to do it" section

template <int size>
using number_type =
    typename std::conditional_t<
        size <= 1,
        std::int8_t,
        typename std::conditional_t<
            size <= 2,
            std::int16_t,
            typename std::conditional_t<
                size <= 4,
                std::int32_t,
                std::int64_t
            >
        >
    >;

template <typename T,
          typename D = std::conditional_t<
                         std::is_integral_v<T>,
                         std::uniform_int_distribution<T>,
                         std::uniform_real_distribution<T> >,
          typename = typename std::enable_if_t<std::is_arithmetic_v<T>>>
std::vector<T> GenerateRandom(T const min, T const max, std::size_t const size) {
    std::vector<T> v(size);

    std::random_device rd{};
    std::mt19937 mt{ rd() };

    D dist{ min, max };

    std::generate(std::begin(v), std::end(v),
        [&dist, &mt] { return dist(mt); });

    return v;
}


void run() {
    {
        using long_type = std::conditional_t<sizeof(void*) <= 4, long, long long>;
        auto n = long_type{42};
    }

    {
        auto n = number_type<2>{ 42 };

        static_assert(sizeof(number_type<1>) == 1);
        static_assert(sizeof(number_type<2>) == 2);
        static_assert(sizeof(number_type<3>) == 4);
        static_assert(sizeof(number_type<4>) == 4);
        static_assert(sizeof(number_type<5>) == 8);
        static_assert(sizeof(number_type<6>) == 8);
        static_assert(sizeof(number_type<7>) == 8);
        static_assert(sizeof(number_type<8>) == 8);
        static_assert(sizeof(number_type<9>) == 8);
    }

    {
        auto v1 = GenerateRandom(1, 10, 10);
        auto v2 = GenerateRandom(1.0, 10.0, 10);
    }
}
} // example_01


int main() {
    std::cout << "[example_01] ->" << std::endl;
    example_01::run();
    std::cout << "-> ok" << std::endl << std::endl;
}

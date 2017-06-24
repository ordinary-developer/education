#include <cstddef>
#include <type_traits>

template <std::size_t, class...>
struct choice;

template <std::size_t N, class T, class... Types>
struct choice_split {
    typedef typename choice<N - 1, Types...>::type type;
};

template <class T, class... Ts>
struct choice_split<0, T, Ts...> {
    typedef T type;
};

template <std::size_t N, class... Types>
struct choice {
    typedef typename choice_split<N, Types...>::type type;
};

template <std::size_t N>
struct choice<N> { };

int main() {
    static_assert(
        std::is_same<int,
                     typename choice<0, int, long, char>::type>::value,
        "error in choice<0>");
    static_assert(
        std::is_same<long,
                     typename choice<1, int, long, char>::type>::value,
        "error in choice<1>");
    static_assert(
        std::is_same<char,
                     typename choice<2, int, long, char>::type>::value,
        "error in choice<2>");

    return 0;
}

#include <iostream>
#include <string>
#include <type_traits>
namespace example_01 { // -> the "how to do it" section

template <typename T,
          typename = typename std::enable_if_t<std::is_arithmetic_v<T> > >
T multiply(T const t1, T const t2) {
    return t1 * t2;
}

template <typename T>
struct pod_wrapper {
    static_assert(std::is_standard_layout_v<T> and std::is_trivial_v<T>, "type is not a POD");

    T value;
}; 

template <typename T>
struct const_wrapper {
    typedef typename std::conditional_t<
        std::is_const_v<T>, T, typename std::add_const_t<T> > const_type;
};

template <typename T>
auto process(T arg) {
    if constexpr (std::is_same_v<T, bool>)
        return not arg;
    else if constexpr (std::is_integral_v<T>)
        return -arg;
    else if constexpr (std::is_floating_point_v<T>)
        return std::abs(arg);
    else
        return arg;
}

void run() {
    {
        auto v1 = multiply(42.0, 1.5);

        using namespace std::string_literals;
        // auto v2 = multiply("42"s, "1.5"s); // compilatino error
    }

    {
        pod_wrapper<int> i{ 42 };

        using namespace std::string_literals;
        //pod_wrapper<std::string> s{"42"s}
    }

    {
        static_assert(std::is_const_v<const_wrapper<int>::const_type>);
        static_assert(std::is_const_v<const_wrapper<int const>::const_type>);
    }

    {
        using namespace std::string_literals;
        auto v1 = process(false);
        auto v2 = process(42);
        auto v3 = process(-42.0);
        auto v4 = process("42"s);
    }

}
} // example_01


namespace example_02 { // -> the "how it works" section

template <typename T>
struct is_void { static const bool value = false; };

template <>
struct is_void<void> { static const bool value = true; };

template <typename T>
struct is_pointer { static const bool value = false; };

template <typename T>
struct is_pointer<T*> { static const bool value = true; };

void run() {
    static_assert(is_void<void>{}.value);
    static_assert(not is_void<int>{}.value);
    static_assert(not is_void<double>{}.value);

    static_assert(is_pointer<int*>{}.value);
    static_assert(not is_pointer<int>{}.value);
}

} // example_02


#include <iostream>
int main() {
    std::cout << "[example_01] -> " << std::endl;
    example_01::run();
    std::cout << "-> ok" << std::endl << std::endl;

    std::cout << "[example_02] -> " << std::endl;
    example_02::run();
    std::cout << "-> ok" << std::endl << std::endl;
} 

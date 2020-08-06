#include <type_traits>
#include <iostream>
#include <string>
namespace example_01 { // -> using 'std::enable_if' with a class tmpl param

template <
    typename T,
    typename = typename    
        std::enable_if<std::is_pod<T>::value, T>::type
>        
class pod_wrapper {
    T value;
};

void run() {
    pod_wrapper<int> w1{};

    struct point {
        int x;
        int y;
    };
    pod_wrapper<point> w2{};

    // pod_wrapper<std::string> w3{}; // will not compile

    std::cout << "[ok]" << std::endl;
}
} // example_01


#include <type_traits>
#include <iostream>
namespace example_02 { // -> using 'std::enable_if' with a func tmpl param

template <
    typename T,
    typename = typename std::enable_if<
        std::is_integral<T>::value, T>::type
>
constexpr auto mul(T const a, T const b) { return a * b; }

void run() {
    auto constexpr const val = mul(1, 2);
    static_assert(2 == val);

    // auto val = mul(1.0, 2.0); // will not compile

    std::cout << "[ok]" << std::endl;
}
} // example_02


#include <type_traits>
#include <iostream>
namespace example_03 { // using aliases with 'std::enable_if'

template <typename Test, typename T = void>
using EnableIf = typename std::enable_if<Test::value, T>::type;

template <typename Test, typename T = void>
using DisableIf = typename std::enable_if<!Test::value, T>::type;

template <typename T, typename = EnableIf<std::is_pod<T>>>
class pod_wrapper {
    T val;
};

template <typename T, typename = EnableIf<std::is_integral<T>>>
constexpr auto mul(T const a, T const b) { return a * b; }

void run() {
    pod_wrapper<int>{};

    auto constexpr const multVal = mul(1, 2);
    static_assert(multVal);

    std::cout << "[ok]" << std::endl;
}
} // example_03


#include <type_traits>
#include <iostream>
namespace example_04 { // using 'std::enable_if' instead of 'static_assert'

template <typename Test, typename T = void>
using EnableIf = typename std::enable_if<Test::value, T>::type;

template <typename Test, typename T = void>
using DisableIf = typename std::enable_if<!Test::value, T>::type;

template <typename T, typename = EnableIf<std::is_integral<T>>>
constexpr auto compute(T const a, T const b) { return a + b; }

template <typename T, typename = DisableIf<std::is_integral<T>>, typename = void>
constexpr auto compute(T const a, T const b) { return a + b; }

void run() {
    auto constexpr const val1 = compute(1, 2);
    static_assert(val1);

    auto constexpr const val2 = compute(1.0, 2.0);
    static_assert(val2 < 3.001 and val2 > 2.999);

    std::cout << "[ok]" << std::endl;
}
} // example_04


#include <iostream>
int main() {
    std::cout << "example_01 => \n"; example_01::run(); std::cout << "\n";
    std::cout << "example_02 => \n"; example_02::run(); std::cout << "\n";
    std::cout << "example_03 => \n"; example_03::run(); std::cout << "\n";
    std::cout << "example_04 => \n"; example_04::run(); std::cout << "\n";

    return 0;
}

#include <iostream>
#include <typeinfo>
namespace example01 {

template <typename ...P> struct sum_type;

template <typename T>
struct sum_type<T> {
    using type = T;
};

template <typename T, typename ...P>
struct sum_type<T, P ...> {
    using type = decltype(T() + typename sum_type<P...>::type());
};

template <typename ...P>
using sum_type_t = typename sum_type<P...>::type;

template <typename T>
inline T sum(T t) { return t; }

template <typename T, typename ...P>
inline sum_type_t<T, P...> sum(T t, P ...p) {
    return t + sum(p...);
}

void run() {
    auto s = sum(-7, 3.7f, 9u, -2.6);
    std::cout << "s is -> " << s << std::endl
              << "and its type is -> " << typeid(s).name() << std::endl;

    auto s2 = sum(-7, 3.7f, 9u, -42.6);
    std::cout << "s2 is -> " << s2 << std::endl
              << "and its type is -> " << typeid(s2).name() << std::endl;
}
}

#include <type_traits>
#include <iostream>
namespace example02 {

template <typename T>
inline T miniumum(T const& t) { return t; }

template <typename T, typename ...P>
//typename std::common_type<T, P...>::type
//inline minimum(T const& t, P const& ... p) 
inline auto minimum(T const& t, P const& ... p) 
{
    using result_type = typename std::common_type<T, P...>::type;
    return std::min(result_type(t), result_type(minimum(p...)));
}

void run() {
    int x{0};
    float y{1};
    double z{2};
    auto status = 
        std::is_same<decltype(x + y + z),
                     std::common_type<decltype(x), 
                                      decltype(y),                     
                                      decltype(z)>>();
    std::cout << "status -> " << status << std::endl;

    std::cout << "min is -> " << minimum(-7, 3.7f, 9u, -2.6) << std::endl;
}

}

int main() {
    example01::run();
    example02::run();

    return 0;
}

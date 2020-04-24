// code for assert working
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <string>
#include <iostream>
#include <cassert>
namespace example_01 { // -> base use of variadic templates
    
template <typename T> 
constexpr T add(T const& value) { 
#if defined(__clang__) || defined(__GNUC__)
    std::cout << __PRETTY_FUNCTION__ << std::endl;    
#endif
    
    return value; 
}
    
template <typename T, typename... Ts>
constexpr T add(T const& head, Ts... rest) {
#if defined(__clang__) || defined(__GNUC__)
    std::cout << __PRETTY_FUNCTION__ << std::endl;    
#endif

    return head + add(rest...);
}
    
void run() {
    using namespace std::string_literals;
    
    // arrange - act
    auto const sum1 = add(1, 2, 3, 4, 5); 
    auto const sum2 = add("hello"s, " "s, "world"s, "!"s);
    
    // assert
    assert(15 == sum1);
    assert("hello world!"s == sum2);
    
    std::cout << "[ok]";
}    
} // example_01


#include <iostream>
namespace example_02 { // -> more elaborate example
    
template <typename T>
constexpr T add(T const& val) {
    return val;
}
    
template <typename T, typename... Ts>
constexpr auto add(T const& head, Ts... tail) {
    return head + add(tail...);
}

void run() {
    using namespace std::string_literals;
    
    // arrage - act
    auto constexpr sum1 = add(1, 2, 3, 4, 5);
    auto const& sum2 = add("hello"s, " "s, "world"s, "!"s);
    auto const& sum3 = add("hello"s, ' ', "world"s, '!');
    
    // assert
    assert(15 == sum1);
    assert("hello world!"s == sum2);
    assert("hello world!"s == sum3);
    
    std::cout << "[ok]";
}
} // example_02


#include <string>
#include <tuple>
#include <iostream>
#include <cassert>
namespace example_03 { // -> using the "sizeof(...)" operator
    
template <typename... T>
constexpr auto make_even_tuple(T... a) {
    static_assert(0 == sizeof...(a) % 2,
        "expected an even number of arguments");
    
    std::tuple<T...> t{ a... };
    return t;
}
void run() {
    // arrage - act
    auto constexpr t1 = make_even_tuple(1, 2, 3, 4);
    auto constexpr size = std::tuple_size<decltype(t1)>::value;
    
    // asert
    assert(4 == size);

    // will not compile
    // auto constexpr t2 = make_even_tuple(1, 2, 3);
    std::cout << "[ok]";
}    
} // example_03


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "example_03 => " << std::endl; example_03::run(); std::cout << std::endl << std::endl;

    return 0;
}
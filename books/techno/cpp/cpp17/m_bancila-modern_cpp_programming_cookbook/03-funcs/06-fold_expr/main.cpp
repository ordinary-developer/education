#ifdef NDEBUG
#undef NDEBUG
#endif

#include <iostream>
#include <cassert>
namespace example_01 { // -> base use of fold expressions 

// left folding with a unary operator
template <typename... Ts>
constexpr auto add1(Ts... args) { return (... + args); }

// left folding with a binary operator    
template <typename... Ts>
constexpr auto add_to_one1(Ts... args) { return (1 + ... + args); }

// right folding with a unary operator    
template <typename... Ts>
constexpr auto add2(Ts...args) { return (args + ...); }

// right folding with a binary operator    
template <typename... Ts>
constexpr auto add_to_one2(Ts... args) { return (args + ... + 1); }

void run() {    
    // arrange - act
    auto constexpr sum1 = add1(1, 2, 3, 4, 5);
    auto constexpr sum2 = add_to_one1(1, 2, 3, 4, 5);
    auto constexpr sum3 = add2(1, 2, 3, 4, 5);
    auto constexpr sum4 = add_to_one1(1, 2, 3, 4, 5);
    
    // assert
    assert(15 == sum1);
    assert(16 == sum2);
    assert(15 == sum3);
    assert(16 == sum4);
    
    std::cout << "[ok]";
}    
} // example_01


#ifdef NDEBUG
#undef NDEBUG
#endif

#include <iostream>
#include <cassert>
namespace example_02 { // -> fold expressions with arbitrary binary functions

template <typename T>
struct wrapper {
    T const& val;
};

template <typename T>
constexpr auto operator<(wrapper<T> const& lhs, wrapper<T> const& rhs) {
    return wrapper<T>{ lhs.val < rhs.val ? lhs.val : rhs.val };
}

template <typename... Ts>
constexpr auto min(Ts&&... args) {
    return (wrapper<Ts>{ args } < ...).val;
}

void run() {
    // arrange - act
    auto constexpr m = min(1, 2, 3, 4, 5);
    
    // assert
    assert(1 == m);
    
    std::cout << "[ok]";
}
} // example_02


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl << std::endl;

    return 0;
}
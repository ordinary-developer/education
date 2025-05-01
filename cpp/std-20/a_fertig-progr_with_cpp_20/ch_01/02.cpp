// a concept with a simple requirement
#include <iostream>
#include <cassert>
namespace example_01 {

template <typename... Args>
concept Addable = requires(Args... args)
{
    (... + args);
};

template <typename... Args>
requires Addable<Args...>
auto Add(Args&&... args) noexcept {  
    return (... + args);
}


void run() {
    const auto val = Add(1, 2, 3, 4, 5);
    assert(15 == val);

    std::cout << "[ ok ] example 01" << std::endl;
}    

} // example_01



// a concept with a nested requirement
#include <iostream>
#include <type_traits>
namespace example_02 {

template <typename T, typename... Ts>
constexpr inline bool are_same_v =
    std::conjunction_v<std::is_same<T, Ts>...>;

template <typename... Args>
concept Addable = requires(Args... args)
{
    (... + args);
    requires are_same_v<Args...>;
    requires sizeof...(Args) > 1;
};

template <typename... Args>
requires Addable<Args...>
auto Add(Args&&... args) noexcept {
    return (... + args);
}


void run() {
    const auto val = Add(1, 2, 3, 4, 5);
    assert(15 == val);

    std::cout << "[ ok ] example 02" << std::endl;
}

} // example_02



// a concpet with a compound requirement
#include <iostream>
#include <type_traits>
#include <cassert>
namespace example_03 {

template <typename T, typename... Ts>
constexpr inline bool are_same_v =
    std::conjunction_v<std::is_same<T, Ts>...>;

template <typename T, typename...>
struct first_arg {
    using type = T;
};

template <typename... Args>
using first_arg_t = typename first_arg<Args...>::type;

template <typename... Args>
concept Addable = requires(Args... args) {
    (... + args);
    requires are_same_v<Args...>;
    requires sizeof...(Args) > 1;

    //{ (... + args) } noexcept;
    //{ (... + args) } -> std::same_as<first_arg_t<Args...>>;

    { (... + args) } noexcept -> std::same_as<first_arg_t<Args...>>;
};

template <typename... Args>
requires Addable<Args...>
auto Add(Args&&... args) noexcept {
    return (... + args);
}


void run() {
    const auto val = Add(1, 2, 3, 4, 5);
    assert(15 == val);
    std::cout << "[ ok ] example 03" << std::endl;
}

} // example 03



// an example with ad hoc constraints
#include <iostream>
#include <type_traits>
#include <cassert>
namespace example_04 {

template <typename T, typename... Ts>
constexpr inline bool are_same_v =
    std::conjunction_v<std::is_same<T, Ts>...>;

template <typename T, typename...>
struct first_arg {
    using type = T;
};

template <typename... Args>
using first_arg_t = typename first_arg<Args...>::type;

template <typename... Args>
requires requires(Args... args)
{
    (... + args);
    requires are_same_v<Args...>;
    requires sizeof...(Args) > 1;
    { (... + args) } noexcept -> std::same_as<first_arg_t<Args...>>;
}
auto Add(Args&&... args) noexcept
{
    return (... + args);
}


void run() {
    const auto val = Add(1, 2, 3, 4, 5);
    assert(15 == val);
    std::cout << "[ ok ] example 04" << std::endl;
}

} // example_04



// an example with an explicitly defined concept
#include <iostream>
#include <type_traits>
#include <cassert>
namespace example_05 {

template <typename T, typename... Ts>
constexpr inline bool are_same_v =
    std::conjunction_v<std::is_same<T, Ts>...>;

template <typename T, typename...>
struct first_arg {
    using type = T;
};

template <typename... Args>
using first_arg_t = typename first_arg<Args...>::type;

template <typename... Args>
concept Addable = requires(Args... args)
{
    (... + args);
    requires are_same_v<Args...>;
    requires sizeof...(Args) > 1;
    { (... + args) } noexcept -> std::same_as<first_arg_t<Args...>>;
};

template <typename... Args>
requires Addable<Args...>
auto Add(Args&&... args) noexcept
{
    return (... + args);
}


void run() {
    const auto val = Add(1, 2, 3, 4, 5);
    assert(15 == val);
    std::cout << "[ ok ] example 05" << std::endl;
}

} // example_05



int main() {
    example_01::run();
    example_02::run();
    example_03::run();
    example_04::run();
    example_05::run();
}
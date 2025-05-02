#include <iostream>
#include <type_traits>
#include <cassert>
namespace example_01 {

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

template <bool nexcept, bool operatorPlus, bool validReturnType>
struct Stub {
    Stub& operator+(const Stub& rhs) noexcept(nexcept) 
        requires(operatorPlus && validReturnType)
    {
        return *this;
    }

    int operator+(const Stub& rhs) noexcept(nexcept)
        requires(operatorPlus && not validReturnType)
    {
        return {};
    }
};

using NoAdd = Stub<true, false, true>;
using ValidClass = Stub<true, true, true>;
using NotNoexcept = Stub<false, true, true>;
using DifferentReturnType = Stub<true, true, false>;


// asserts
static_assert(not Addable<int, double>);

static_assert(not Addable<int>);

static_assert(Addable<int, int>);

// is not compiled
//static_assert(Addable<ValidClass, ValidClass>);

static_assert(not Addable<NoAdd, NoAdd>);

static_assert(not Addable<NotNoexcept, NotNoexcept>);

static_assert(
    not Addable<DifferentReturnType, DifferentReturnType>);


void run() {
    std::cout << "[ ok ] example 01" << std::endl;
}    

}



int main() {
    example_01::run();
}
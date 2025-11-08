#include <iostream>
#include <type_traits>
#include <cassert>
namespace example_01 {

template <typename V, typename W>
concept IsSame = std::is_same_v<V, W>;

template <typename T>
concept AlwaysTrue = true;

template <typename T, typename U>
requires IsSame<T, U>
auto add(const T& t, const U& u)
{
    return t + u;
}

template <typename T, typename U>
requires IsSame<T, U> and AlwaysTrue<T>
auto add(const T& t, const U& u)
{
    return t + u;
}

void run() {
    int a = 1;
    int b = 2; 
    assert(3 == add(a, b));

    std::cout << "[ ok ] example 01" << std::endl;
}

} // example_01



#include <iostream>
#include <type_traits>
#include <cassert>
namespace example_02 {

template <typename V, typename W>
concept IsSameHelper = std::is_same_v<V, W>;

template <typename V, typename W>
concept IsSame = IsSameHelper<V, W> and IsSameHelper<W, V>;

template <typename T>
concept AlwaysTrue = true;

template <typename T, typename U>
requires IsSame<U, T>
auto add(const T& t, const U& u) {
    return t + u;
}

template <typename T, typename U>
requires IsSame<T, U> and AlwaysTrue<T>
auto add(const T& t, const U& u)
{
    return t + u;
}

void run() {
    int a = 1;
    int b = 2;
    assert(3 == add(a, b));

    std::cout << "[ ok ] example 02" << std::endl;
}

} // example_02


int main() {
    example_01::run();
    example_02::run();
}
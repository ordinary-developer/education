// an examples without concepts
#include <iostream>
#include <type_traits>
namespace example_01 {

template <typename T, typename... Ts>
constexpr inline bool are_same_v =
    std::conjunction_v<std::is_same<T, Ts> ...>;

template <typename T, typename...>
struct first_arg {
    using type = T;
};

template <typename...Args>
using first_arg_t = typename first_arg<Args...>::type;

template <typename... Args>
std::enable_if_t<are_same_v<Args...>, first_arg_t<Args...>>
Add(const Args&... args) noexcept
{
    return (... + args);
}


void run() {
    std::cout << "[ ok ] example 01" << std::endl;

    const int x = Add(2, 3, 4, 5);
    std::cout << "\tx value = (" << x << ")" << std::endl;

    const int y = Add(2, 3);
    std::cout << "\ty value = (" << y << ")" << std::endl;

    // here a compilation error will occur
    //const int z = Add(2, 3.0);
}

} // example 01


// an example with concepts
#include <iostream>
#include <type_traits>
namespace example_02 {

template <typename T, typename... Ts>
constexpr inline bool are_same_v =
    std::conjunction_v<std::is_same<T, Ts> ...>;

template <typename... Args>
requires are_same_v<Args...>
auto Add(Args&&... args) noexcept
{
    return (... + args);
}

void run() {
    std::cout << "[ ok ] example 02" << std::endl;

    const int x = Add(2, 3, 4, 5);
    std::cout << "\tx value = (" << x << ")" << std::endl;

    const int y = Add(2, 3);
    std::cout << "\ty value = (" << y << ")" << std::endl;

    // here a compilation error will occur
    //const int z = Add(2, 3.0);
}
} // example_02


#include <iostream>
int main()
{
    example_01::run();
    example_02::run();

    return 0;
} 

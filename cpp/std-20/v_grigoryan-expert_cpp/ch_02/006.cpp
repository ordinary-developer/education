#include <iostream>


auto foo1() -> int {
    std::cout << "foo in alternative function syntax" << std::endl;
    return 0;
}

auto foo2() {
    std::cout << "In C++14 syntax" << std::endl;
    return 0;
}

auto getRatio1(const bool minimum) {
    if (minimum)
        return 12;

    return 18;
}

auto getRatio2(const bool minimum) { return (minimum ? 12 : 18); }


int main() {
    const auto val1 = foo1();
    std::cout << val1 << std::endl;

    const auto val2 = foo2();
    std::cout << val2 << std::endl;

    std::cout << getRatio1(true) << std::endl;
    std::cout << getRatio2(true) << std::endl;
}

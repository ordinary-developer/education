#include <iostream>


template <typename Type1, typename Type2>
auto myFunc1(const Type1& t1, const Type2& t2) -> decltype(t1 + t2) {
    return t1 + t2;
}

template <typename Type1, typename Type2>
auto myFunc2(const Type1& t1, const Type2& t2) {
    return t1 + t2;
}

auto main() -> int {
    std::cout << myFunc1(2, 4) << std::endl;
    std::cout << myFunc2(2, 4) << std::endl;

    return 0;
}


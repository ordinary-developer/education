template <bool Condition, class IfTrue, class IfFalse>
struct my_conditional {
    typedef IfFalse type;
};

template <class IfTrue, class IfFalse>
struct my_conditional<true, IfTrue, IfFalse> {
    typedef IfTrue type;
};

#include <typeinfo>
#include <iostream>
int main() {
    my_conditional<true, int, float>::type a{};
    my_conditional<false, int, float>::type b{};
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;

    return 0;
}

#include <type_traits>

template <class Check, class... Args> struct is_member;

template <class Check, class Head, class... Rest>
struct is_member_helper : std::conditional
                            <std::is_same<Check,Head>::value,
                             std::true_type,
                             is_member<Check, Rest...>>::type { };

template <class Check, class... Args>
struct is_member : is_member_helper<Check, Args...> { };

template <class Check>
struct is_member<Check> : std::false_type {};

template <class IsMember, class T>
struct get_member { typedef T type; };

template <class T>
struct get_member<std::false_type, T> { typedef int type; };

template <class T>
struct promote {
    typedef typename get_member<typename is_member<T,
        bool, unsigned char, signed char, char, unsigned short, short>
            ::type, T>::type type;
};

#include <iostream>
#include <typeinfo>
int main() {
    promote<bool>::type variable1{};
    promote<long>::type variable2{};
    std::cout << typeid(variable1).name() << std::endl;
    std::cout << typeid(variable2).name() << std::endl;

    return 0;
}

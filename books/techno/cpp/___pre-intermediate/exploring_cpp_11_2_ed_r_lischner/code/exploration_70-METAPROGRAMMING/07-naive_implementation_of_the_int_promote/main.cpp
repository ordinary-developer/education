template <class T> struct promote { typedef T type; };
template<> struct promote<bool> { typedef int type; };
template<> struct promote<char> { typedef int type; };
template<> struct promote<signed char> { typedef int type; };
template<> struct promote<unsigned char> { typedef int type; };
template<> struct promote<short> { typedef int type; };
template<> struct promote<unsigned short> { typedef int type; };

#include <iostream>
#include <typeinfo>
int main() {
    promote<bool>::type variable1{};
    promote<long>::type variable2{};
    std::cout << typeid(variable1).name() << std::endl;
    std::cout << typeid(variable2).name() << std::endl;

    return 0;
}

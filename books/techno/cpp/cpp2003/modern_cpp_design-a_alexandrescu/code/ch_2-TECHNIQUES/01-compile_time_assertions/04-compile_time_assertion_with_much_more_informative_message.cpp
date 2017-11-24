#include <iostream>

template<bool> struct CompileTimeChecker
{
    CompileTimeChecker(...);
};
template<> struct CompileTimeChecker<false> { };
#define STATIC_CHECK(expr, msg) \
{\
    class ERROR_##msg { };\
    (void)sizeof(CompileTimeChecker<0 != (expr)>((ERROR_##msg())));\
}

template <class To, class From>
To safe_reinterpret_cast(From from)
{
    STATIC_CHECK((sizeof(From) <= sizeof(To)),
                 Destination_Type_Too_Narrow);

    //return reinterpret_cast<To>(from);
    return To();
}

int main() {
    int a = 5;
    char b = safe_reinterpret_cast<char>(a);

    if (0 == (sizeof(int) <= sizeof(char)))
        std::cout << "1" << std::endl;

    return 0;
}

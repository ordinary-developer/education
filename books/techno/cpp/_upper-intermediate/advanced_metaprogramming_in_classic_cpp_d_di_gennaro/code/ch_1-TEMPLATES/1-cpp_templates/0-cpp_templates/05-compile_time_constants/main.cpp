#include <climits>

template <int N> 
class SomeClass { };

template <int N>
class AnotherClass
{
    SomeClass<N> myMember_;
};

template <int N, int K>
struct MyTemplate
{
    static const int PRODUCT = N * K;
};

int main() {
    // COMPILE-TIME CONSTANTS

    // integer literals
    SomeClass<27> a1;
    SomeClass<CHAR_BIT> a2;
    SomeClass<0x05> a3;

    // sizeof and similar non-standard language operators
    // with an integer result (__alignof__ etc.)
    SomeClass<sizeof(int)> b1;

    // non-type template parameters 
    // (in the context of an "outer" template)
    AnotherClass<27> c1;

    // static constants of integer type 
    SomeClass<MyTemplate<10,12>::PRODUCT> d1;

    // some standard macros (__LINE__ etc.)
    SomeClass<__LINE__> e1;

    return 0;
}

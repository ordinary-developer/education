template <typename T, typename T::type N>
struct SomeClass { };

struct S1 {
    typedef int type;
};

template <typename T>
struct A
{
    static const int X = 7;
};

template <>
struct A<char>
{
    typedef double X;
};
    

template <typename T>
struct B {
    static const int N = sizeof(A<T>::X);
};

int main() {
    SomeClass<S1, 3> x;

    return 0;
}

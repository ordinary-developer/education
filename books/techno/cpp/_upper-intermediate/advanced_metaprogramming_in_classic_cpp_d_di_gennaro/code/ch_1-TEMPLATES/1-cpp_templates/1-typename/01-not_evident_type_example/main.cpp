template <typename T>
struct MyClass {
    typedef double Y;
    typedef T Type;
};

template <>
struct MyClass<int>
{
    static const int Y = 314;
    typedef int Type; 
};

int Q = 8;

template <typename T>
void SomeFunc() {
    MyClass<T>::Y * Q;
}

template <typename X>
class AnotherClass {
    // MyClass<X>::Type t1_; // error
    typename MyClass<X>::Type t2_; // ok
    MyClass<double>::Type t3_; // ok

    typename MyClass<X>::Y member1_;
    // typename MyClass<double>::Y member2_; // error
};

int main() {
    AnotherClass<float> ac;
    return 0;
}

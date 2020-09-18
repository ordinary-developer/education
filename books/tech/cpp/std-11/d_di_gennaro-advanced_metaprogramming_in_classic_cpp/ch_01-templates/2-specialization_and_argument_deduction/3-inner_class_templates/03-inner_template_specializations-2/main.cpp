template <typename T>
struct outer {
    template <typename X> struct inner { };
};

template <>
struct outer<int> {
    template <typename X> struct inner { };
};


// error
/*
template <typename T, typename X>
bool f(outer<T>::inner<X>) { return true; }
*/


int main() {
    outer<double>::inner<void> I1;
    outer<int>::inner<void> I2;
    // I1 = I2; // error

    return 0;
}

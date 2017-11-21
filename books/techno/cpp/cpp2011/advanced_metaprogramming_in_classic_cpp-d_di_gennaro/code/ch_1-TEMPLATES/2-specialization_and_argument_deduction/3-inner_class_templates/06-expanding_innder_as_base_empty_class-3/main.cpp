template <typename X, typename T>
struct basic_inner {
    template <typename T2>
    basic_inner& operator=(const basic_inner<X, T2>&) {
        return *this;
    }
};

template <typename T>
struct outer {
    template <typename X>
    struct inner : public basic_inner<X, T> {
        template <typename ANOTHER_T>
        inner& operator=(const basic_inner<X, ANOTHER_T>& that) {
            static_cast<basic_inner<X, T>&>(*this) = that;
            return *this;
        }
    };
};

template <>
struct outer<int> {
    template <typename X>
    struct inner : public basic_inner<X, int> {
        template <typename ANOTHER_T>
        inner& operator= (const basic_inner<X, ANOTHER_T>& that) {
            static_cast<basic_inner<X, int>&>(*this) = that;
            return *this;
        }
    };
};

int main( ) {
    outer<double>::inner<void> I1;
    outer<int>::inner<void> I2;
    I1 = I2;

    return 0;
}

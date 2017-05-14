template <typename X>
struct basic_inner { };

template <typename T>
struct outer {
    template <typename X>
    struct inner : public basic_inner<X> {
        inner& operator=(const basic_inner<X>& that) {
            static_cast<basic_inner<X>&>(*this) = that;
            return *this;
        }
    };
};

template <>
struct outer<int> {
    template <typename X>
    struct inner : public basic_inner<X> {
        inner& operator=(const basic_inner<X>& that) {
            static_cast<basic_inner<X>&>(*this) = that;
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

struct A {
    template <typename X, typename Y>
    struct B {
        void do_it() { }
    };

    void f() {
        B<int, int> b;
        b.do_it();
    }
};

template <typename X>
struct A::B<X, X> {
    void do_it() { }
};

// adding a full specialization of B will trigger a compiler error
/*
template <>
struct A::B<int, int> {
    void do_it() { }
};
*/

int main() {
    A a;
    a.f();
    return 0;
}

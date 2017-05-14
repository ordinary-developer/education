template <int I>
struct arg { };

template <int I>
arg<I> f(arg<I + 1>) { return arg<I>(); }


int main() {
    arg<3> a;
    // here an error will be
    // the compiler will not solve the equation I + 1 == 3
    // f(a);

    arg<2 + 1> b;
    // error again
    // f(b);

    return 0;
}

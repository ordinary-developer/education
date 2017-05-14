template <int I>
struct arg { };

template <int I>
arg<I + 1> f(arg<I>) { return arg<I + 1>(); }


int main() {
    arg<3> a;
    f(a);       // will deduce I=3 and thus return arg<4>

    return 0;
}

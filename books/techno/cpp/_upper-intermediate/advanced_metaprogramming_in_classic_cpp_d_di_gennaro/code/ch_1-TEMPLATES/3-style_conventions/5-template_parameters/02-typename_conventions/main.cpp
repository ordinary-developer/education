int foo(double x) { return 5 + x; }

template <typename R, typename A>
inline R apply(R (*F)(A), A arg) {
    return F(arg);
}

template <typename R, typename A1, typename A2>
inline R apply(R (*F)(A1, A2), A1 arg1, A2 arg2) {
    return F(arg1, arg2);
}


int main() {
    double x = apply(&foo, 3.14);

    return 0;
}

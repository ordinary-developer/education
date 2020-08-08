double f(double x) { return x + 1; }

template <typename T>
T g(T x) { return x + 1; }

typedef double (*FUNC_T)(double);

int main() {
    FUNC_T f1 = f;
    FUNC_T f2 = g<double>;

    return 0;
}

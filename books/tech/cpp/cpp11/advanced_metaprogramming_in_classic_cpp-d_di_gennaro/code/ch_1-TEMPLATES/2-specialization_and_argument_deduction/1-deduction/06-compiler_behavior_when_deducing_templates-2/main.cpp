template <typename T>
void f() { }

template <int N>
void f() { }

int main() {
    f<double>(); // invokes the first f
    f<7>();      // invokes the second f

    return 0;
}

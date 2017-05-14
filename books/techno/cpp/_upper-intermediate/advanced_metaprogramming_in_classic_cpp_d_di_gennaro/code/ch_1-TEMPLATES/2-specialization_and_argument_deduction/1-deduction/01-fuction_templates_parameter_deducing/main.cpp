template <typename T>
struct arg { };

template <typename T>
void f(arg<T>) { }

template <typename X>
void g(arg<const X>) { }


int main() {
    arg<int*> a;
    f(a); // will deduce T = int*

    arg<const int> b;
    f(b); // will deduce T = const int
    g(b); // will deduce T = int

    return 0;
}


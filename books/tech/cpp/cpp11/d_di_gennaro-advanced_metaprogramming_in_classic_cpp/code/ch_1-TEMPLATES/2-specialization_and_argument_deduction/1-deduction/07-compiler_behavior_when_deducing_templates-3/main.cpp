template <typename T>
void g(T x) { }

template <typename T>
void h(T x) { }

void h(double x) { }

int main() {
    double pi = 3.14;

    g<double>(pi);  // ok, calls g<double>

    h<double>(pi); // unexpected: still calls the first h

    return 0;
}

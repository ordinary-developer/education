template <double F(int)>
struct A { };

template <double (*F)(int)>
struct B { };

double f(int) { return 3.1415; }

int main() {
    A<f> t1;
    B<f> t2;

    return 0;
}

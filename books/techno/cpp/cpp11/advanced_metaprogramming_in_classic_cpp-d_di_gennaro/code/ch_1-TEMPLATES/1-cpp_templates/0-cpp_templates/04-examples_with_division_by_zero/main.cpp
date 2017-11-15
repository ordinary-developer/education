template <int N> struct tricky { };

template <int N>
struct tricky1 
{
    int f(int i = 0) { return i/N; }
};

template <int N>
struct tricky2 
{
    int f() { return N/N; }
};


int main() {
    // will not be compiled
    // tricky<0/0> t;

    tricky1<0> t1;
    t1.f(); // will be compiled but a runtime error will be here

    tricky2<0> t2;
    t2.f(); // will be compiled but a runtime error will be here

    return 0;
}

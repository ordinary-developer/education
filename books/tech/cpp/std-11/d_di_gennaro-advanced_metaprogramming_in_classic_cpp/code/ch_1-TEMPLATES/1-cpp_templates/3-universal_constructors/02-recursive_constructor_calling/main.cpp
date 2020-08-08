struct base {
    base() { }

    template <typename T>
    base(T x) { } 
};

struct derived : base {
    derived() { }

    derived(const derived& that)
        : base(that) { }
};


int main() {
    derived d1;
    derived d2 = d1;

    return 0;
}

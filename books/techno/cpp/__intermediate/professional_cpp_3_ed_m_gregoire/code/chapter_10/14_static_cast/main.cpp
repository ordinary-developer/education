class Base {
    public:
        Base() { }
        virtual ~Base() { }
};

class Derived : public Base {
    public:
        Derived() { }
        virtual ~Derived() { }
};

auto main() -> int {
    int i = 3;
    int j = 4;
    double result = static_cast<double>(i) / j;

    Base* b;
    Derived* d = new Derived();
    b = d;
    d = static_cast<Derived*>(b);

    Base base;
    Derived derived;
    Base& br = derived;
    Derived& dr = static_cast<Derived&>(br);

    // here is an error
    Base* bnew = new Base();
    Derived* dnew = static_cast<Derived*>(bnew);

    return 0;
}

#include <iostream>
#include <typeinfo>

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
    Base* b;
    Derived* d = new Derived();
    b = d;
    d = dynamic_cast<Derived*>(b);

    Base base;
    Derived derived;
    Base& br = base;
    try {
        Derived& dr = dynamic_cast<Derived&>(br);
    }
    catch (const std::bad_cast& e) {
        std::cout << "Bad cast!\n";
    }
    return 0;
}

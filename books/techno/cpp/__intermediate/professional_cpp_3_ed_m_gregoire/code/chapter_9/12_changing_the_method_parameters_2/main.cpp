#include <iostream>

class Super {
    public:
        Super() { }
        virtual void someMethod() {
            std::cout << "Super's method" << std::endl;
        }
};

class Sub : public Super {
    public:
        Sub() { }
        using Super::someMethod;
        virtual void someMethod(int i) { 
            std::cout << "Sub's method with int" << std::endl;
        }
        virtual void someOtherMethod() { }
};

auto main() -> int {
    Super* p = new Sub();
    p->someMethod();

    Sub sub;
    sub.someMethod();
    sub.someMethod(3);

    return 0;
}

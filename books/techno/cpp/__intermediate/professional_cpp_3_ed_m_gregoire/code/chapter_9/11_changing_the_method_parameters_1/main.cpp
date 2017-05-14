#include <iostream>

class Super {
    public:
        Super() { }
        virtual void someMethod() { std::cout << "Super's method" << std::endl; }
    
};

class Sub : public Super {
    public:
        Sub() { }
        virtual void someMethod(int i) { 
            std::cout << "Sub's method with int parameter" << std::endl;
        }
        virtual void someOtherMethod() { } 
};

auto main() -> int {
    Super* p = new Sub();
    p->someMethod();

    Sub sub;
    Super& ref = sub;
    ref.someMethod();

    Sub mySub;
    // will  not compile
    // mySub.someMethod();
    return 0;
}

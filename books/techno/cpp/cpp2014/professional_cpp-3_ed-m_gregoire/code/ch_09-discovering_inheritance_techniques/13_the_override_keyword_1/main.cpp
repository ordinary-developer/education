#include <iostream>


class Super {
    public:
        Super() { }
        virtual void someMethod(double d) {
            std::cout << "Super's method" << std::endl;
        }
};

class Sub : public Super {
    public:
        Sub() { }
        virtual void someMethod(int i) { 
            std::cout << "Sub's method with int" << std::endl;
        }
};

auto main() -> int {
    Sub mySub;
    Super& ref = mySub;
    ref.someMethod(1.2);
    ref.someMethod(1);

    Sub sub;
    sub.someMethod(1);
    sub.someMethod(1.1);

    return 0;
}

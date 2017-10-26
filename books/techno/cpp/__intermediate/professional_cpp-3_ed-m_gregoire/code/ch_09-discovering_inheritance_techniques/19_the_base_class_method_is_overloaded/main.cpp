#include <iostream>
#include <string>

class Super {
    public:
        virtual void overload() { 
            std::cout << "Super's overload()" << std::endl; 
        }
        virtual void overload(int i) {
            std::cout << "Super's overload(int i)" << std::endl;
        }
};

class Sub : public Super {
    public:
        virtual void overload() override {
            std::cout << "Sub's overload()" << std::endl;
        }
};

auto main() -> int {
    Sub mySub;
    mySub.overload();
    // will not compile
    // mySub.overload(2);
    Super* ptr = &mySub;
    ptr->overload(7);

    return 0;
}

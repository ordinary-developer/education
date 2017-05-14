#include <iostream>

class Super {
    public:
        virtual void go(int i = 2) {
            std::cout << "Super's go with i = " << i << std::endl;
        }
};

class Sub : public Super {
    public:
        virtual void go(int i = 7) override {
            std::cout << "Sub's go with i = " << i << std::endl;
        }
};

auto main() -> int {
    Super mySuper;
    Sub mySub;
    Super& mySuperReferenceToSub = mySub;
    mySuper.go();
    mySub.go();
    mySuperReferenceToSub.go();

    return 0;
}

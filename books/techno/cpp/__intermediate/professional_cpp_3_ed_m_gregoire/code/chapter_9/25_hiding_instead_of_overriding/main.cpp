#include <iostream>


class Super {
    public:
        void go() { std::cout << "go() called on Super" << std::endl; }
};

class Sub : public Super {
    public:
        void go() { std::cout << "go() called on Sub" << std::endl; }
};

auto main() -> int {
    Sub mySub;
    mySub.go();

    Super& ref = mySub;
    ref.go();

    return 0;
}


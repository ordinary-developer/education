#include <iostream>

class Super {
    public:
        Super(int i);
};
Super::Super(int i) {
    std::cout << "Super's constructor" << std::endl;
}

class Sub : public Super {
    public:
        Sub();
};

Sub::Sub() : Super(7) { 
    std::cout << "Sub's constructor" << std::endl;
}


auto main() -> int {
    Sub sub;
    return 0;
}

#include <iostream>
#include <string>

class Super {
    public:
        Super(const std::string& str) { 
            std::cout << "Super' constructor" << std::endl;
        }
};

class Sub : public Super {
    public:
        using Super::Super;
        Sub(int i) : Super("sdf") {
            std::cout << "Sub' constructor" << std::endl;
        }
};

auto main() -> int {
    Super super("Hello");
    Sub sub(1);
    Sub sub2("hello");

    return 0;
}

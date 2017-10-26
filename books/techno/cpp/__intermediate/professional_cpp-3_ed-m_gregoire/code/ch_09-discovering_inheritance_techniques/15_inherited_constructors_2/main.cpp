#include <iostream>
#include <string>

class Super {
    public:
        Super(const std::string& str) : Super(3) {
        }
        Super(float f) {
            std::cout << "Super's constructor" << std::endl;
        }
};

class Sub : public Super {
    public:
        using Super::Super;
        Sub(float f) : Super(f) {
            std::cout << "Sub's constructor" << std::endl;
        }
};

auto main() -> int {
    Sub sub1("hello");
    Sub sub2(1.23f);
    return 0;
}

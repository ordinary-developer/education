#include <iostream>
#include <string>

class Super1 {
    public:
        Super1(float f) {
            std::cout << "Super1's float constructor" << std::endl;
        }
};

class Super2 {
    public:
        Super2(const std::string& str) {
            std::cout << "Super2's string constructor" << std::endl;
        }
        Super2(float f) {
            std::cout << "Super2's float constructor" << std::endl;
        }
};

class Sub : public Super1, public Super2 {
    public:
        using Super1::Super1;
        using Super2::Super2;
        Sub(char c) : Super1(1), Super2(2) { 
            std::cout << "Sub's char constructor" << std::endl;
        }
        Sub(float f) : Super1(1), Super2(2) {
            std::cout << "Sub's float constructor" << std::endl;
        }

};

auto main() -> int {
    Super1 super1(1);
    Super2 super2(2);
    Sub sub(1.0f);
    return 0;
}

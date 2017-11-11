#include <iostream>

class Super {
    public:
        Super() { }
        ~Super() { }
};

class Sub : public Super {
    public:
        Sub() { mString = new char[30]; }
        ~Sub() { delete [] mString; }
    private:
        char* mString;
};

auto main() -> int {
    Super* ptr = new Sub();
    delete ptr;

    return 0;
}

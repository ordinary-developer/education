#include <iostream>
#include <string>

class Super {
    public:
        Super(const std::string& str) : mStr(str) {}
    private:
        std::string mStr;
};

class Sub : public Super {
    public:
        using Super::Super;
        Sub(int i) : Super(""), mInt(i) { }
    private:
        int mInt = 0;
};

auto main() -> int {
    Sub s1(2);
    Sub s2("hello world!");

    return 0;
}

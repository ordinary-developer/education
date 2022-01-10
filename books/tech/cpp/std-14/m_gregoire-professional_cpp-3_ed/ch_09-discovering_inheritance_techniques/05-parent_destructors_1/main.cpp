#include <iostream>


class Something {
    public:
        Something() { std::cout << "2"; }
        virtual ~Something() { std::cout << "2"; }
};

class Parent {
    public:
        Parent() { std::cout << "1"; }
        virtual ~Parent() { std::cout << "1"; }
};

class Child : public Parent {
    public:
        Child() { std::cout << "3"; }
        virtual ~Child() { std::cout << "3"; }
    private:
        Something mDataMember;
};

auto main() -> int {
    Child myChild;
    return 0;
}

#include <iostream>

class Something {
    public:
        Something() { std::cout << "2"; }
};

class Parent {
    public:
        Parent() { std::cout << "1"; }
};

class Child : public Parent {
    public:
        Child() { std::cout << "3"; }
    private:
        Something mDataMember;
};

int main() {
    Child myChild;
    return 0;
}

#include <iostream>

class Mixin1 {
    public:
        Mixin1(int i) : value_{i} { }
        virtual void Mixin1Func() { 
            std::cout << "Mixin1: " << value_ << std::endl;
        }

    private:
        int value_;
};

class Mixin2 {
    public:
        Mixin2(int i) : value_{i} { }
        virtual void Mixin2Func() { 
            std::cout << "Mixin2: " << value_ << std::endl;
        }

    private:
        int value_;
};

template <typename... Mixins>
class MyClass : public Mixins... {
    public:
        MyClass(const Mixins&... mixins) : Mixins(mixins)... { }
        virtual ~MyClass() = default;
};

int main() {
    MyClass<Mixin1, Mixin2> a{Mixin1{11}, Mixin2{22}};
    a.Mixin1Func();
    a.Mixin2Func();

    return 0;
}

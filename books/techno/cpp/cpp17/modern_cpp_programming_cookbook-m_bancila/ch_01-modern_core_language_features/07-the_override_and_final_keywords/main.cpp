// region [how to do it]
namespace example_01 {
    
class Base {
    virtual void foo() = 0;
    virtual void bar() {}
    virtual void foobar() = 0;
};    
    
void Base::foobar() {}
    
class Derived1 : public Base {
    virtual void foo() override = 0;
    virtual void bar() override {}
    virtual void foobar() override {}
};    
    
class Derived2 : public Derived1 {
    virtual void foo() override final {}    
};    
    
class Derived3 final : public Derived1 {
    virtual void foo() override {}    
};    
    
void run() {
    Derived2 derived2{};    
    Derived3 derived3{};
}    
}
// endregion [how to do it]

// region [how it works]
namespace example_02 {
    
class foo {
    int final = 0;
    void override() {}
};    
    
void run() {
    foo f{};
} // example_03
} 
// endregion

#include <iostream>
int main() {
    example_01::run();
    example_02::run();
    
    std::cout << "DONE" << std::endl;
    
    return 0;
}
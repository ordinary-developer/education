#include <iostream>
#include <memory>

class Base {
    public:
        virtual void doWork() 
        {
            std::cout << "Base->doWork()" << std::endl;
        }
};

class Derived : public Base {
    public:
        virtual void doWork() 
        {
            std::cout << "Derived->doWork()" << std::endl;
        }
};

int main() {
    std::unique_ptr<Base> upb = 
        std::make_unique<Derived>();
    upb->doWork();
}

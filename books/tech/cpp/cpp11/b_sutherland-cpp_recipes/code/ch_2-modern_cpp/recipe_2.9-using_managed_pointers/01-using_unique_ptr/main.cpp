#include <iostream>
#include <memory>

class MyClass {
    public:
        MyClass() {
            std::cout << "Constructing!" << std::endl;
        }

        ~MyClass() {
            std::cout << "Destructing!" << std::endl; 
        }

        int GetValue() const { return m_Value; }

    private:
        int m_Value{ 10 };
};


int main() {
    std::unique_ptr<MyClass> uniquePointer{ 
        std::make_unique<MyClass>() };
    std::cout << uniquePointer->GetValue() << std::endl;

    return 0;
}

#include <iostream>
#include <memory>


class MyClass {
    public:
        MyClass(const std::string& name, int value)
            : m_Name{ name }, m_Value{ value }
        {
            std::cout << "Constructing!" << std::endl;
        }

        ~MyClass() {
            std::cout << "Destructing!" << std::endl;
        }

        const std::string& GetName() const {
            return m_Name;
        }

        int GetValue() const { return m_Value; }

    private:
        std::string m_Name;
        int m_Value;
};

using MySharedPtr = std::shared_ptr<MyClass>;

auto PassSharedPtr(MySharedPtr ptr) {
    std::cout << "In Function Name: " << ptr->GetName() << std::endl;
    return ptr;
}


int main() {
    auto sharedPointer = std::make_shared<MyClass>("MyClass", 10);

    {
        auto newSharedPointer = PassSharedPtr(sharedPointer);
        if (sharedPointer)
            std::cout << "First Object Name: " 
                      << sharedPointer->GetName() << std::endl;

        std::cout << "Second Object Name: " 
                  << newSharedPointer->GetName() << std::endl;
    }
    
    return 0;
}

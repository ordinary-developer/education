#include <iostream>
#include <memory>

class MyClass {
    public:
        MyClass(const std::string& name, int value)
            : m_name{ name }, m_value{ value } 
        {
            std::cout << "Constructing!" << std::endl;
        }

        ~MyClass() {
            std::cout << "Destructing!" << std::endl;
        }

        const std::string& GetName() const {
            return m_name;
        }

        int GetValue() const {
            return m_value;
        }

    private:
        std::string m_name;
        int m_value;
};

using MySharedPtr = std::shared_ptr<MyClass>;
using MyWeakPtr = std::weak_ptr<MyClass>;

auto PassSharedPtr(MySharedPtr ptr) {
    std::cout << "In Function Name: " << ptr->GetName() << std::endl;
    return ptr;
}

int main() {
    MyWeakPtr weakPtr{};
    {
        auto sharedPointer = std::make_shared<MyClass>("MyClass", 10);
        weakPtr = sharedPointer;

        {
            auto newSharedPointer = PassSharedPtr(sharedPointer);
            if (sharedPointer) 
                std::cout << "First Object Name: "  
                          << sharedPointer->GetName() << std::endl;

            std::cout << "Second Object Name: "
                      << newSharedPointer->GetName() << std::endl;

            auto sharedFromWeak1 = weakPtr.lock();
            if (sharedFromWeak1)
                std::cout << "Name From Weak1: " 
                          << sharedFromWeak1->GetName()
                          << std::endl;
        }
    }

    auto sharedFromWeak2 = weakPtr.lock();
    if (!sharedFromWeak2)
        std::cout << "Shared Pointer out of scope!" << std::endl;

    return 0;
}

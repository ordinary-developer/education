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
            std::cout << "Destruction!" << std::endl;
        }

        const std::string& GetName() const {
            return m_Name;
        }

        int GetValue() const {
            return m_Value;
        }

    private:
        std::string m_Name;
        int m_Value;
};

using MyUniquePtr = std::unique_ptr<MyClass>;

auto PassUniquePtr(MyUniquePtr ptr) {
    std::cout << "In Function Name: " << ptr->GetName() << std::endl;
    return ptr;
}


int main() {
    auto uniquePointer = std::make_unique<MyClass>("MyClass", 10);
    auto newUniquePointer = PassUniquePtr(std::move(uniquePointer));

    if (uniquePointer) 
        std::cout << "First object name: " << uniquePointer->GetName()
                  << std::endl;

    std::cout << "Second object name: " << newUniquePointer->GetName()
              << std::endl;

    return 0;
}

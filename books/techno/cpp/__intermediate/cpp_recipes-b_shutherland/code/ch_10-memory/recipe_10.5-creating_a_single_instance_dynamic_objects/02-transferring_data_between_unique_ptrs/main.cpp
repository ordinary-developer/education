#include <iostream>
#include <memory>

class MyClass {
    public:
        MyClass(int value) : m_Number{ value } { }
        ~MyClass() { std::cout << "Destroying " << m_Number << std::endl; }

        void operator=(const int value) { m_Number = value; }

        int GetNumber() const { return m_Number; }

    private:
        int m_Number{ 0 };
};

using UniqueMyClass = std::unique_ptr<MyClass>;

void CreateUniqueObject(UniqueMyClass& referenceToUniquePtr)
{
    UniqueMyClass uniqueMyClass{ std::make_unique<MyClass>(10) };
    std::cout << std::hex << std::showbase;
    std::cout << "Address in uniqueMyClass " << uniqueMyClass.get() << std::endl;
    referenceToUniquePtr.swap(uniqueMyClass);
    std::cout << "Address in uniqueMyClass " << uniqueMyClass.get() << std::endl;
}


int main() {
    std::cout << "Begin main!" << std::endl;

    UniqueMyClass uniqueMyClass{};
    CreateUniqueObject(uniqueMyClass);
    std::cout << "Address in main's uniqueMyClass " << uniqueMyClass.get() << std::endl;

    std::cout << std::dec << std::noshowbase << "Back in Main" << std::endl;

    return 0;
}

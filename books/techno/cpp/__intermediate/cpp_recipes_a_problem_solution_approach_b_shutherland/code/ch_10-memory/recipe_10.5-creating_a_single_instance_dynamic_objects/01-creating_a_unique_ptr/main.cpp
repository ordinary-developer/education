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

void CreateUniqueObject()
{
    UniqueMyClass uniqueMyClass{ std::make_unique<MyClass>(10) };
}


int main() {
    std::cout << "Begin main!" << std::endl;
    CreateUniqueObject();
    std::cout << "Back in Main" << std::endl;

    return 0;
}

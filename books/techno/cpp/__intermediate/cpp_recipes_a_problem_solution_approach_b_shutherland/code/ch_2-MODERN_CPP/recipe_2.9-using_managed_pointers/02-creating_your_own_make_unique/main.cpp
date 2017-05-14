#include <iostream>
#include <memory>

#if __cplusplus > 200400L && __cplusplus < 201200L
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args... args)
{
    return std::unique_ptr<T>{ new T(args...) };
}
#endif 

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

int main() {
    std::unique_ptr<MyClass> uniquePointer{
        std::make_unique<MyClass>("MyClass", 10) };

    std::cout << uniquePointer->GetName() << std::endl;
    std::cout << uniquePointer->GetValue() << std::endl;

    return 0;
}

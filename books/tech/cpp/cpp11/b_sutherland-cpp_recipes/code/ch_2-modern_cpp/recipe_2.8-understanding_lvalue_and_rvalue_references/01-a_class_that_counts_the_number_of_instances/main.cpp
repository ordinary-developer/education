#include <iostream>

class MyClass {
    public:
        MyClass() { 
            ++(*m_Member); 
        }
        
        ~MyClass() {
            --(*m_Member);
            m_Member = nullptr;
        }

        int GetValue() const {
            return *m_Member;
        }

    private:
        static int s_Counter;
        int* m_Member{ &s_Counter };

};

int MyClass::s_Counter{ 0 };

int main() {
    auto object1 = MyClass();
    std::cout << object1.GetValue() << std::endl;

    {
        auto object2 = MyClass();
        std::cout << object2.GetValue() << std::endl;
        std::cout << object1.GetValue() << std::endl;
    }

    auto object3 = MyClass();
    std::cout << object3.GetValue() << std::endl;
    std::cout << object1.GetValue() << std::endl;

    return 0;
}

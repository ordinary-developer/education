#include <iostream>

class MyClass {
    public:
        MyClass() : m_Instance{ m_Count++ } 
        {
            std::cout << "Constructor called on " << m_Instance << std::endl;
        }
        ~MyClass() {
            std::cout << "Destructor called on " << m_Instance << std::endl;
        }

    private:
        int m_Instance{ -1 };
        static int m_Count;
};

int MyClass::m_Count{ 0 };


int main() {
    MyClass myClass1{};

    {
        MyClass myClass2{};

        {
            MyClass myClass3{};
        }
    }

    return 0;
}


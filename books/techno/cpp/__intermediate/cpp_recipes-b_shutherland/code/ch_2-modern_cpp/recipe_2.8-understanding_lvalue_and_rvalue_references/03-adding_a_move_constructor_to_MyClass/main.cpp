#include <iostream>

class MyClass {
    public:
        MyClass() {
            ++(*m_Member);

            std::cout << "Constructing: " << GetValue() << std::endl;
        }

        ~MyClass() {
            if (m_Member) {
                --(*m_Member);
                m_Member = nullptr;

                std::cout << "Destructing: " << s_Counter 
                          << std::endl;
            }
            else
                std::cout << "Destroying a moved-from instance"
                          << std::endl;
        }

        MyClass(const MyClass& rhs)
            : m_Member{ rhs.m_Member }
        {
            ++(*m_Member);

            std::cout << "Copying: " << GetValue() << std::endl;
        }

        MyClass(MyClass&& rhs) 
            : m_Member{ rhs.m_Member }
        {
            std::cout << std::hex << std::showbase;
            std::cout << "Moving: " << &rhs << " to " << this
                      << std::endl;
            std::cout << std::noshowbase << std::dec;
            rhs.m_Member = nullptr;
        }

        int GetValue() const { return *m_Member; }

    private:
        static int s_Counter;
        int* m_Member{ &s_Counter };
};

int MyClass::s_Counter{ 0 };

MyClass CopyMyClass(MyClass parameter) {
    return parameter;
}

int main() {
    auto object1 = MyClass();

    {
        auto object2 = MyClass();
    }

    auto object3 = MyClass();
    auto object4 = CopyMyClass(object3);

    return 0;
}

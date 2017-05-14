#include <iostream>

class MyClass {
    public:
        MyClass() = default;
        ~MyClass() {
            std::cout << "Destroying " << m_Number << std::endl;
        }

        void operator=(const int value) {
            m_Number = value;
        }

    private:
        int m_Number{ 0 };
};

int main() {
    const unsigned int NUM_ELEMENTS{ 5 };
    MyClass* pObjects{ new MyClass[NUM_ELEMENTS] };
    pObjects[0] = 100;
    pObjects[1] = 45;
    pObjects[2] = 31;
    pObjects[3] = 90;
    pObjects[4] = 58;

    delete[] pObjects;
    pObjects = nullptr;

    return 0;
}

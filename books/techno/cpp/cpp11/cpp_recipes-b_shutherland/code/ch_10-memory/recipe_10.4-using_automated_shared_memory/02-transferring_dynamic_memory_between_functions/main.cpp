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

using SharedMyClass = std::shared_ptr<MyClass>;

void ChangeSharedValue(SharedMyClass sharedMyClass) {
    if (nullptr != sharedMyClass)
        *sharedMyClass = 100;
}

int main() {
    SharedMyClass sharedMyClass{ new MyClass(10) };
    ChangeSharedValue(sharedMyClass);

    return 0;
}

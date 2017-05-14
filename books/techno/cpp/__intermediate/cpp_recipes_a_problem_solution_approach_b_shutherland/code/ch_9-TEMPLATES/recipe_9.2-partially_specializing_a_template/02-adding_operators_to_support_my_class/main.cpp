#include <iostream>

class MyClass {
    public:
        MyClass() = default;
        MyClass(int value) : m_Value{ value } { }
        MyClass(int number1, int number2) : m_Value{ number1 + number2 } { }
        
        int GetValue() const { return m_Value; }
        
        MyClass operator+(const MyClass& other) const {
            return m_Value + other.m_Value;
        }
        
    private:
        friend std::ostream& operator<<(std::ostream& os, const MyClass& myClass);
        int m_Value{ 0 };
};

std::ostream& operator<<(std::ostream& os, const MyClass& myClass) {
    os << myClass.GetValue();
    return os;
}

template <typename T>
T Add(const T& a, const T& b) {
    return a + b;
}

template <typename T>
void Print(const T& value1, const T& value2, const T& result) {
    std::cout << "The result of adding " << value1 << " to " << value2
              << " is " << result << std::endl;
}

int main()
{
   const MyClass number1{ 1 };
   const MyClass number2{ 2 };
   const MyClass result{ Add(number1, number2) };
   Print(number1, number2, result);
   
   return 0;
}

#include <iostream>

class MyClass {
    public:
        MyClass() = default;
        MyClass(int value) : m_Value{ value } { }
        MyClass(int number1, int number2) : m_Value{ number1 + number2 } { }
        
        int GetValue() const { return m_Value; }
        
    private:
        int m_Value{ 0 };
};

template <typename T>
T Add(const T& a, const T& b) {
    return a + b;
}

template <>
MyClass Add(const MyClass& myClass1, const MyClass& myClass2) {
    return MyClass(myClass1.GetValue(), myClass2.GetValue());
}

template <typename T>
void Print(const T& value1, const T& value2, const T& result) {
    std::cout << "The result of adding " << value1 << " to " << value2
              << " is " << result << std::endl;
}

template <>
void Print(const MyClass& value1, const MyClass& value2, const MyClass& result) {
    std::cout << "The result of adding " << value1.GetValue() 
              << " to " << value2.GetValue() << " is " << result.GetValue()
              << std::endl;
}

int main()
{
   const MyClass number1{ 1 };
   const MyClass number2{ 2 };
   const MyClass result{ Add(number1, number2) };
   Print(number1, number2, result);
   
   return 0;
}

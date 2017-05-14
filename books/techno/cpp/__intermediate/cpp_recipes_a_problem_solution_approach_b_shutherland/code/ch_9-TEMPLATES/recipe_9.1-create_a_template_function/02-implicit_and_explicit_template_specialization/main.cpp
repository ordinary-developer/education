#include <iostream>

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
   const int number1{ 1 };
   const int number2{ 2 };
   const int intResult{ Add(number1, number2) };
   Print(number1, number2, intResult);
   
   const float floatResults{ Add(static_cast<float>(number1), static_cast<float>(number2)) };
   Print<float>(number1, number2, floatResults);
   
   return 0;
}

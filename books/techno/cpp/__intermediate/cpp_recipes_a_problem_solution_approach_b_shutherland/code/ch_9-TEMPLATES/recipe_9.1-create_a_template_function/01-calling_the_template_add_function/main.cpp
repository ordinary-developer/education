#include <iostream>

template <typename T>
T Add(const T& a, const T& b) {
    return a + b;
}

int main()
{
   const int number1{ 1 };
   const int number2{ 2 };
   const int result{ Add(number1, number2) };
   
   std::cout << "The result of adding " << std::endl;
   std::cout << number1 << std::endl;
   std::cout << " to " << std::endl;
   std::cout << number2 << std::endl;
   std::cout << " is " << std::endl;
   std::cout << result << std::endl;
   
   return 0;
}

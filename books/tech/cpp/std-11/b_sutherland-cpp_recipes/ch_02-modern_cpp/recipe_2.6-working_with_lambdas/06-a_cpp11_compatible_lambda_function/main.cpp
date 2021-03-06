#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <iostream>
#include <typeinfo>
#include <vector>


using MyArray = std::array<uint32_t, 5>;
using MyVector = std::vector<MyArray::value_type>;

void PrintArray(
    const std::function<void(MyArray::value_type)>& myFunction)
{
    MyArray myArray{ 1, 2, 3, 4, 5 };

    std::for_each(std::begin(myArray),
                  std::end(myArray),
                  myFunction);
}

int main() {
    MyVector myCopy{};
    auto myClosure = [&myCopy](const MyArray::value_type& number)  {
        std::cout << number << std::endl;
        myCopy.push_back(number);
    };
    std::cout << typeid(myClosure).name() << std::endl;

    PrintArray(myClosure);

    std::cout << std::endl << "My Copy: " << std::endl;
    std::for_each(std::begin(myCopy),
                  std::end(myCopy),
                  [](const MyVector::value_type&  number) {
                      std::cout << number << std::endl;
                  });

    return 0;
}

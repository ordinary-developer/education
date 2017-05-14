#include <iostream>
#include <string>


auto main() -> int {
    int i = 7;
    std::cout << i << std::endl;

    char ch = 'a';
    std::cout << ch << std::endl;

    std::string myString = "Hello World";
    std::cout << myString << std::endl;

    int j = 11;
    std::cout << "The value of j is " << j << "!" << std::endl;

    std::cout << "Line 1" << std::endl << "Line 2" << std::endl 
              << "Line 3" << std::endl;

    return 0;
}

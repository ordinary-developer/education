#include <string>
#include <iostream>


auto main() -> int {
    std::string str1;

    str1.insert(end(str1), 'h');
    str1.insert(end(str1), 'e');
    str1.push_back('l');
    str1.push_back('l');
    str1.push_back('o');

    for (const auto& letter : str1) {
        std::cout << letter;
    }
    std::cout << std::endl;

    for (auto iterator = begin(str1); 
              iterator != end(str1);
            ++iterator) 
    {
        std::cout << *iterator;
    }
    std::cout << std::endl;

    return 0;
}

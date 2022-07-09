#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, unsigned long long> phoneBook;
    phoneBook["Donald"] = 202'566'1111;
    phoneBook["Melania"] = 202'456'1111;
    phoneBook["Francis"] = 39'06'6982;
    phoneBook["Elizabeth"] = 44'020'7930'4832;

    std::cout << "The pope's number is " << phoneBook["Francis"] << std::endl;

    // C++17 iteration
    for (const auto & [name, number] : phoneBook)
        std::cout << name << " can be reached at " << number << std::endl;
    std::cout << std::endl;

    // C++11 iteration
    for (const auto & element : phoneBook)
        std::cout << element.first << " can be reached at " << element.second << std::endl;
    std::cout << std::endl;

    // another C++11 iteration
    for (const std::pair<const std::string, unsigned long long> & element : phoneBook)
        std::cout << element.first << " can be reached at " << element.second << std::endl;
    std::cout << std::endl;

    // since C++11
    std::pair myPair{ false, 77.50 };
    auto [myBool, myNumber] = myPair;

    // prior to C++17
    std::pair<bool, double> myPair2{ false, 77.50 };
    bool myBool2 = myPair2.first;
    double myNumber2 = myPair2.second;
}

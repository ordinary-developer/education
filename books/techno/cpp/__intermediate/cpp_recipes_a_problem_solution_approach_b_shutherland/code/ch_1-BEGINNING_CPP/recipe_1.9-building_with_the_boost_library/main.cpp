#include <iostream>
#include "boost/format.hpp"

using namespace std;

int main() {
    std::cout << "Enter your first name: " << std::endl;
    std::string firstName;
    std::cin >> firstName;

    std::cout << "Enter your surname: " << std::endl;
    std::string surname;
    std::cin >> surname;

    auto formatedName = boost::format("%1% %2%"s) % firstName % surname;
    std::cout << "You said your name is: " << formatedName << std::endl;

    return 0;
}

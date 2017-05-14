#include <algorithm>
#include <vector>
#include <iostream>


auto main() -> int {
    int number;
    std::vector<int> myVector;

    while (true) {
        std::cout << "Enter a number to add (0 to stop): ";
        std::cin >> number;
        if (0 == number) {
            break;
        }
        myVector.push_back(number);
    }

    while (true) {
        std::cout << "Enter a number to lookup (0 to stop): ";
        std::cin >> number;
        if (0 == number) {
            break;
        }
        auto endIterator = end(myVector);
        auto iterator = find(begin(myVector), endIterator, number);
        if (iterator == endIterator) {
            std::cout << "Could not find " << number << std::endl;
        }
        else {
            std::cout << "Found " << *iterator << std::endl;
        }
    }

    return 0;
}

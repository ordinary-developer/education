#include <algorithm>
#include <vector>
#include <iostream>


bool perfectScore(int number) {
    return (number >= 100);
}

auto main() -> int {
    int number;
    std::vector<int> myVector;

    while (true) {
        std::cout << "Enter a test score to add (0 to stop): ";
        std::cin >> number;
        if (0 == number) {
            break;
        }
        myVector.push_back(number);
    }

    const auto endIterator = end(myVector);
    auto iterator = find_if(begin(myVector), endIterator, perfectScore);
    if (endIterator == iterator) {
        std::cout << "No perfect scores" << std::endl;
    }
    else {
        std::cout << "Found a \"perfect\" score of " << *iterator << std::endl;
    }

    return 0;
}

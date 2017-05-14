#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>


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

    auto endIterator = end(myVector);

    auto iterator = find_if(begin(myVector), endIterator,
            std::bind(std::greater_equal<>(), std::placeholders::_1, 100));
    // or
    iterator = find_if(begin(myVector), endIterator,
            [](int i) { return i >= 100; });

    if (endIterator == iterator) {
        std::cout << "No perfect scores" << std::endl;
    }
    else {
        std::cout << "Found a \"perfect\" score of " << *iterator
                  << std::endl;
    }

    return 0;
}

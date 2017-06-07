#include <algorithm>
#include <vector>
#include <iostream>


auto main() -> int {

    int number;
    std::vector<int> numbers;

    while (true) {
        std::cout << "Enter a test score to add (0 to stop): ";
        std::cin >> number;
        if (0 == number) {
            break;
        }
        numbers.push_back(number);
    }

    const auto endIterator = end(numbers);
    auto iterator = find_if(begin(numbers), endIterator, [](int i) { return i >= 100; });
    if (endIterator == iterator) {
        std::cout << "No perfect scores" << std::endl;
    }
    else {
        std::cout << "Found a \"perfect\" score of " << *iterator << std::endl;
    }

    return 0;
}

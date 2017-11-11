#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

bool perfectScore(int number) {
    return (number >= 100);
}

auto main() -> int {
    int number;

    std::vector<int> vector;
    while (true) {
        std::cout << "Enter a test score to add (0 to stop): ";
        std::cin >> number;
        if (0 == number) {
            break;
        }
        vector.push_back(number);
    }

    auto endIterator = end(vector);
    std::function<bool(int)> f = perfectScore;
    auto iterator = find_if(begin(vector), endIterator, std::not1(f));

    if (end(vector) == iterator) {
        std::cout << "All perfect scores" << std::endl;
    }
    else {
        std::cout << "Found a \"Less-that-perfect\" score of " 
                  << *iterator << std::endl;
    }

    return 0;

}

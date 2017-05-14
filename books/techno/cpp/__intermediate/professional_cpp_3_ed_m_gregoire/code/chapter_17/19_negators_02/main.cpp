#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

bool perfectScore(int number) {
    return number >= 100;
}


auto main() -> int {
    int number = 0;
    
    std::vector<int> numbers;
    while (true) {
        std::cout << "Enter a test score to add (0 to stop): ";
        std::cin >> number;
        if (0 == number) {
            break;
        }
        numbers.push_back(number);
    }

    auto iterator = find_if(begin(numbers), end(numbers),
            [](int i) { return i < 100; });

    if (end(numbers) == iterator) {
        std::cout << "All perfect scores" << std::endl;
    }
    else {
        std::cout << "Found a \"less-than-perfect\" score of " 
                  << *iterator << std::endl;
    }

    return 0;
}

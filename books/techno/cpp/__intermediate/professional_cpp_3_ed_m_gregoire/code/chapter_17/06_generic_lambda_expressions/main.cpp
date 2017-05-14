#include <algorithm>
#include <vector>
#include <iostream>


auto main() -> int {
    std::vector<int> integers { 11, 55, 101, 200 };
    std::vector<double> doubles { 11.1, 55.5, 200.2 };

    auto isGreaterThan100 = [] (auto i) { return i > 100; };

    auto iterator1 = find_if(begin(integers), end(integers), isGreaterThan100);
    if (end(integers) != iterator1) {
        std::cout << "Found a value > 100: " << *iterator1 << std::endl;
    }
    // an example with lambdas
    iterator1 = find_if(begin(integers), end(integers), [] (auto i) {
            return i > 100;
    });
    if (end(integers) != iterator1) {
        std::cout << "[LAMBDA] Found a value > 100:" 
                  << *iterator1 << std::endl;
    }

    auto iterator2 = find_if(begin(doubles), end(doubles), isGreaterThan100);
    if (end(doubles) != iterator2) {
        std::cout << "Found a value > 100: " << *iterator2 << std::endl;
    }
    // an example with lambdas
    iterator2 = find_if(begin(doubles), end(doubles), [] (auto i) {
            return i > 100;
    });
    if (end(doubles) != iterator2) {
        std::cout << "[LAMBDA] Found a value > 100: " << *iterator2 
                  << std::endl;
    }

    return 0;
}

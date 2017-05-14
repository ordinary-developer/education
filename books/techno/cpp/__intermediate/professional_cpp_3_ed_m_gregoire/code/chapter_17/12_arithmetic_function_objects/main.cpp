#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <functional>


double geometricMean(const std::vector<int>& numbers) {
    double mult = accumulate(
                    begin(numbers), end(numbers), 1, std::multiplies<int>());
    return pow(mult, 1.0 / numbers.size());
}

double geometricMeanTransparent(const std::vector<int>& numbers) {
    double mult = accumulate(
                    begin(numbers), end(numbers), 1, std::multiplies<>());
    return pow(mult, 1.0 / numbers.size());
}

auto main() -> int {
    std::plus<int> myPlus;
    int res = myPlus(4, 5);
    std::cout << res << std::endl;

    std::vector<int> myVector;

    int number;
    while (true) {
        std::cout << "Enter a test score to add (0 to stop): ";
        std::cin >> number;
        if (0 == number) {
            break;
        }
        myVector.push_back(number);
    }

    std::cout << "The geometric mean is " << geometricMean(myVector) 
              << std::endl;
    std::cout << "The geometric mean is (tranparent function object) "
              << geometricMeanTransparent(myVector) << std::endl;

    std::vector<int> numbers1 {1, 2, 3};
    double result1 = accumulate(
                      begin(numbers1), end(numbers1), 1.1, std::multiplies<>());
    std::cout << result1 << std::endl;

    std::vector<int> numbers2 { 1, 2, 3 };
    double result2 = accumulate(begin(numbers2), end(numbers2), 1.1,
                                std::multiplies<int>());
    std::cout << result2 << std::endl;

    return 0;
}

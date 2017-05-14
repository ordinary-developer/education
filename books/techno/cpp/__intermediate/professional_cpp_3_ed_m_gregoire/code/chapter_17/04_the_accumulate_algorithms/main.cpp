#include <numeric>
#include <vector>
#include <cmath>
#include <iostream>


double arithmeticMean(const std::vector<int>& numbers) {
    double sum = accumulate(begin(numbers), end(numbers), 0);
    return sum / numbers.size();
}

int product(int number1, int number2) {
    return number1 * number2;
}

double geometricMean(const std::vector<int> numbers) {
    double mult = accumulate(begin(numbers), end(numbers), 1, product);
    return pow(mult, 1.0 / numbers.size());
}

double geometricMeanLambda(const std::vector<int> numbers) {
    double mult = accumulate(begin(numbers), end(numbers), 1, 
            [](int number1, int number2) { return number1 * number2; });
    return pow(mult, 1.0 / numbers.size());
}


auto main() -> int {
    std::vector<int> numbers;
    int number;

    while (true) {
        std::cout << "Enter a test score to add (0 to stop): ";
        std::cin >> number;
        if (0 == number) {
            break;
        }
        numbers.push_back(number);
    }

    std::cout << "The arithmetic mean is " << arithmeticMean(numbers) 
              << std::endl;
    std::cout << "The geometric mean is " << geometricMean(numbers) 
              << std::endl;

    std::cout << "The geometci mean (Lambda version) is " 
              << geometricMeanLambda(numbers) << std::endl;

    return 0;
}

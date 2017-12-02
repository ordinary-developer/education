#include <functional>
#include <iostream>
#include <vector>
namespace example01 {

template <typename CONTAINER_TYPE, typename UNARY_FUNCTION_TYPE>
void myForEach(CONTAINER_TYPE const& container, 
               UNARY_FUNCTION_TYPE const& unaryFunction)
{
    for (auto const& element : container)
        unaryFunction(element);
}

template <typename CONTAINER_TYPE, typename UNARY_OPERATION_TYPE>
void myTransform(CONTAINER_TYPE& container, 
                 UNARY_OPERATION_TYPE unaryOperator)
{
    for (auto& element : container)
        element = unaryOperator(element);
}

template <typename NUMBERTYPE>
class ToSquare {
    public:
        NUMBERTYPE operator()(NUMBERTYPE const& number) const noexcept {
            return number * number;
        }
};

template <typename TYPE>
void printOnStdOut(TYPE const& thing) {
    std::cout << thing << ", ";
}

void run() {
    std::vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    myTransform(numbers, ToSquare<int>{});

    std::function<void(int)> printNumberOnStdOut = printOnStdOut<int>;
    myForEach(numbers, printNumberOnStdOut);
    std::cout << std::endl;
}
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
namespace example02 {

class IsPalindrome {
    public:
        bool operator()(std::string const& word) const {
            auto const middleOfWord = std::cbegin(word) + word.size() / 2;
            return std::equal(std::cbegin(word), 
                              middleOfWord,
                              std::crbegin(word));
        }
};

void run() {
    std::vector<std::string> someWords { "dad", "hello", "radar", 
                                         "vector", "deleveled",
                                         "foo", "bar", "racecar",
                                         "ROTOR", "", "C++", 
                                         "aibohphobia" };
    someWords.erase(std::remove_if(std::begin(someWords),
                                   std::end(someWords),
                                   IsPalindrome{}),
                    std::end(someWords));

    std::for_each(std::cbegin(someWords), 
                  std::cend(someWords),
                  [](auto const& word) {
                    std::cout << word << ", "; });
    std::cout << std::endl;
}
}

#include <numeric>
#include <iostream>
#include <vector>
namespace example03 {
void run() {
    std::vector<int> numbers{ 12, 45, -102, 33, 78, -8, 100, 2017, -110 };

    int const sum{ std::accumulate(std::cbegin(numbers), 
                                   std::cend(numbers),
                                   0) };
    std::cout << "The sum is: " << sum << std::endl;

    int const maxValue =
        std::accumulate(std::cbegin(numbers),
                        std::cend(numbers),
                        0,
                        [](int const value1, int const value2) {
                            return value1 > value2 ? value1 : value2; });
    std::cout << "The highest number is: " << maxValue << std::endl;
}
}

#include <iostream>
namespace example04 {

template <typename... PACK>
int subtractFold(int minuend, PACK... subtrahends) {
    return (minuend - ... - subtrahends);
}

void run() {
    int const result = subtractFold(1000, 55, 12, 333, 1, 12);
    std::cout << "The result is: " << result << std::endl;
}
}

#include <iostream>
namespace example05 {

template <typename... TYPE>
bool containsEvenValue(TYPE const&... argument) {
    return ((0 == argument % 2) || ...);
}

void run() {
    bool const result1{ containsEvenValue(10, 7, 11, 9, 33, 14) };
    bool const result2{ containsEvenValue(17, 7, 11, 9, 33, 29) };

    std::cout << std::boolalpha;
    std::cout << "result1 is " << result1 << "\n";
    std::cout << "result2 is " << result2 << std::endl;
}
}

int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();

    return 0;
}


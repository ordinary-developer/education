#include <map>
namespace example01 {

void run() {
    auto theAnswerToAllQuestions = 42;

    std::map<int, int> mymap{};
    auto iter = std::begin(mymap);

    const auto gravitationalAccelerationOnEarth = 9.80665;

    constexpr auto sum = 10 + 20 + 12;

    auto strings = { "The", "big", "brown", "fox", "jumps", "over", "the",
                     "lazy", "dog" };

    auto numberOfStrings = strings.size();
}

} // namespace example01

#include <map>
#include <string>
namespace example02 {

void run() {
    std::map<unsigned int, std::string> words{};
    auto wordIterator = begin(words);
}
} // namespace example02

#include <vector>
namespace example03 {
void run() {
    std::vector<int> integerSequence1{};
    integerSequence1.push_back(14);
    integerSequence1.push_back(33);
    integerSequence1.push_back(69);

    std::vector<int> integerSequence2{ 14, 33, 69, 104, 222, 534 };
}
} // namespace example03

#include <string>
#include <vector>
namespace example04 {

using WordList = std::vector<std::string>;

class LexicalRepository {
    public:
        explicit LexicalRepository(
                std::initializer_list<const char*> const& words)
        {
            wordList_.insert(std::begin(wordList_), 
                             std::cbegin(words),
                             std::cend(words));
        }

    private:
        WordList wordList_;
};

void run() {
    LexicalRepository repo{ "The", "big", "brown", "fox", "jumps", "over",
                            "the", "lazy", "dog" };

}
} // namespace example04

#include <utility>
#include <map>
#include <vector>
namespace example05 {

auto function() {
    std::vector<std::map<std::pair<int, double>, int>> returnValue;
    return returnValue;
}

void run() {
    function();

    auto square = [](int x) { return x * x; };
}

} // namespace example05

#include <iostream>
namespace example06 {

constexpr int multiply(int const multiplier, int const multiplicand) {
    return multiplier * multiplicand;
}

constexpr unsigned long long factorial(unsigned short const n) {
    return n > 1 ? n * factorial(n - 1) : 1;
}

void run() {
    constexpr int theAnswerToAllQuestions = multiply(7, 6);

    unsigned short number{6};
    auto result1{ factorial(number) };
    constexpr auto result2{ factorial(10) };
    std::cout << "result1: " << result1 << ", result2: " << result2
              << std::endl;
}
} // namespace example06


#include <iostream>
namespace example07 {

template <typename T>
constexpr T pi = T(3.1415926);

template <typename T>
constexpr T computeCircumference(T const radius) {
    return 2 * radius * pi<T>;
}
void run() {
    constexpr long double radius = 10.0L;
    constexpr long double circumference = computeCircumference(radius);
    std::cout << circumference << std::endl;
}
} // namespace example07

#include <iostream>
#include <cmath>
namespace example08 {

class Rectangle {
    public:
        constexpr Rectangle() = delete;
        constexpr Rectangle(double const width, double const height):
            width_{ width }, height_{ height } {}

        constexpr double getWidth() const { return width_; }
        constexpr double getHeight() const { return height_; }

        constexpr double getArea() const { return width_ * height_; }

        constexpr double getLengthOfDiagonal() const {
            return std::sqrt(std::pow(width_, 2.0) 
                   + std::pow(height_, 2.0));
        }

    private:
        double width_;
        double height_;
};

void run() {
    constexpr Rectangle americanFootballPlayingField{ 48.76, 110.0 };
    constexpr double area = americanFootballPlayingField.getArea();
    constexpr double diagonal =
        americanFootballPlayingField.getLengthOfDiagonal();

    std::cout << "The area of an American Football playing field is "
              << area << " "
              << "m^2 and the length of its diagonal is "
              << diagonal << "m." << std::endl;
}

} // namespace example08


int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();
    example06::run();
    example07::run();
    example08::run();

    return 0;
}

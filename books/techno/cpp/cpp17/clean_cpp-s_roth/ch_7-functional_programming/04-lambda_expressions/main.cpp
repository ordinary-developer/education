#include <iostream>
namespace example01 {
void run() {
    auto multiply = [](double const multiplicand, double const multiplier) {
        return multiplicand * multiplier;
    };
    std::cout << multiply(10.0, 50.0) << std::endl;

    std::cout << [](double const multiplicand, double const multiplier) {
                    return multiplicand * multiplier;
                 }(50.0, 10.0) 
              << std::endl;
}
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
namespace example02 {
void run() {
    std::vector<std::string> quote{ "That's", "one", "small", "step",
                                    "for", "a", "man,", "one", "giant",
                                    "leap", "for", "mankind." };
    std::vector<std::string> result{};

    std::transform(std::begin(quote), 
                   std::end(quote),
                   std::back_inserter(result),
                   [](std::string const& word) { 
                      return "<" + word + ">"; });

    std::for_each(std::begin(result), 
                  std::end(result),
                  [](std::string const& word) { 
                    std::cout << word << " "; });
    std::cout << std::endl;
}
}

#include <complex>
#include <iostream>
namespace example03 {
void run() {
    auto square = [](auto const& value) noexcept { 
        return value * value; };

    auto const result1 = square(12.56);
    auto const result2 = square(25u);
    auto const result3 = square(-6);
    auto const result4 = square(std::complex<double>(4.0, 2.5));

    std::cout << "result1 is " << result1 << "\n";
    std::cout << "result2 is " << result2 << "\n";
    std::cout << "result3 is " << result3 << "\n";
    std::cout << "result4 is " << result4 << "\n";
}
}

int main() {
    example01::run();
    example02::run();
    example03::run();

    return 0;
}

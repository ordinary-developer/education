#include <iostream>
#include <iterator>
#include <vector>
#include <cstddef>
#include <algorithm>
namespace example01 {

class IncreasingNumberGenerator {
    public:
        int operator()() noexcept { return number_++; }

    private:
        int number_{0};
};

void run() {
    IncreasingNumberGenerator numberGenerator{};
    std::cout << numberGenerator() << std::endl;
    std::cout << numberGenerator() << std::endl;
    std::cout << numberGenerator() << std::endl;

    using Numbers = std::vector<int>;
    std::size_t const AMOUNT_OF_NUMBERS{ 100 };
    Numbers numbers(AMOUNT_OF_NUMBERS);
    std::generate(std::begin(numbers), 
                  std::end(numbers), 
                  IncreasingNumberGenerator{});
    std::copy(std::cbegin(numbers),
              std::cend(numbers),
              std::ostream_iterator<Numbers::value_type>{ std::cout,
                                                          " " });
    std::cout << std::endl;
}
}

#include <random>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include <cstddef>
namespace example02 {

template <typename NUMTYPE>
class RandomNumberGenerator {
    public:
        RandomNumberGenerator() {
            mersenneTwisterEngine_.seed(randomDevice_());
        }

        NUMTYPE operator()() {
            return distribution_(mersenneTwisterEngine_);
        }

    private:
        std::random_device randomDevice_;
        std::uniform_int_distribution<NUMTYPE> distribution_;
        std::mt19937_64 mersenneTwisterEngine_;
};

using Numbers = std::vector<short>;
std::size_t const AMOUNT_OF_NUMBERS{ 100 };

Numbers createVectorFilledWithRandomNumbers() {
    RandomNumberGenerator<short> randomNumberGenerator{};
    Numbers randomNumbers(AMOUNT_OF_NUMBERS);
    std::generate(std::begin(randomNumbers), 
                  std::end(randomNumbers),
                  std::ref(randomNumberGenerator));
    return randomNumbers;
}

void printNumbersOnStdOut(Numbers const& randomNumbers) {
    std::copy(std::cbegin(randomNumbers),
              std::cend(randomNumbers),
              std::ostream_iterator<Numbers::value_type>{ std::cout, 
                                                          " "});
    std::cout << std::endl;
}

void run() {
    Numbers randomNumbers = createVectorFilledWithRandomNumbers();
    printNumbersOnStdOut(randomNumbers);
}
}

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstddef>
namespace example03 {

class IncreasingNumberGenerator {
    public:
        int operator()() noexcept { return number_++; }

    private:
        int number_{0};
};

class ToSquare {
    public:
        constexpr int operator()(int const value) const noexcept {
            return value * value;
        }
};

void run() {
    using Numbers = std::vector<int>;

    std::size_t const AMOUNT_OF_NUMBERS{ 100 };
    Numbers numbers(AMOUNT_OF_NUMBERS);
    std::generate(std::begin(numbers), 
                  std::end(numbers),
                  IncreasingNumberGenerator{});
    std::transform(std::begin(numbers), 
                   std::end(numbers),
                   std::begin(numbers),
                   ToSquare());

    std::copy(std::cbegin(numbers), 
              std::cend(numbers),
              std::ostream_iterator<Numbers::value_type>{ std::cout, 
                                                          " " });
    std::cout << std::endl;
}

}

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstddef>
namespace example04 {
class IncreasingNumberGenerator {
    public:
        int operator()() noexcept { return number_++; }

    private:
        int number_{0};
};

class ToSquare {
    public:
        constexpr int operator()(int const value) const noexcept {
            return value * value;
        }
};

class IsAnOddNumber {
    public:
        constexpr bool operator() (int const value) const noexcept {
            return 0 != value % 2;
        }
};

void run() {
    using Numbers = std::vector<int>;

    std::size_t const AMOUNT_OF_NUMBERS{ 100 };
    Numbers numbers(AMOUNT_OF_NUMBERS);
    std::generate(std::begin(numbers), 
                  std::end(numbers),
                  IncreasingNumberGenerator{});
    std::transform(std::begin(numbers), 
                   std::end(numbers),
                   std::begin(numbers),
                   ToSquare());
    numbers.erase(std::remove_if(std::begin(numbers),
                                 std::end(numbers),
                                 IsAnOddNumber{}),
                  std::end(numbers));

    std::copy(std::cbegin(numbers), 
              std::cend(numbers),
              std::ostream_iterator<Numbers::value_type>{ std::cout, 
                                                          " " });
    std::cout << std::endl;
}
}


#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstddef>
#include <type_traits>
namespace example05 {
class IncreasingNumberGenerator {
    public:
        int operator()() noexcept { return number_++; }

    private:
        int number_{0};
};

class ToSquare {
    public:
        constexpr int operator()(int const value) const noexcept {
            return value * value;
        }
};

template <typename INTTYPE>
class IsAnOddNumber {
    public:
        static_assert(std::is_integral<INTTYPE>::value,
                      "IsAnOddNumber requires an integer type "
                      "for its template parameter INTTYPE!");
        constexpr bool operator()(INTTYPE const value) const noexcept {
            return 0 != value % 2;
        }
};

void run() {
    using Numbers = std::vector<int>;

    std::size_t const AMOUNT_OF_NUMBERS{ 100 };
    Numbers numbers(AMOUNT_OF_NUMBERS);
    std::generate(std::begin(numbers), 
                  std::end(numbers),
                  IncreasingNumberGenerator{});
    std::transform(std::begin(numbers), 
                   std::end(numbers),
                   std::begin(numbers),
                   ToSquare());
    numbers.erase(std::remove_if(std::begin(numbers),
                                 std::end(numbers),
                                 IsAnOddNumber<Numbers::value_type>{}),
                  std::end(numbers));

    std::copy(std::cbegin(numbers), 
              std::cend(numbers),
              std::ostream_iterator<Numbers::value_type>{ std::cout, 
                                                          " " });
    std::cout << std::endl;
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


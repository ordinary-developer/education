#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

// dumb functions
int computeSomeValue1() { return 1; }
int computeSomeValue2() { return 2; }
int computeDivisor(int value1, int value2) { return 2; }

template <typename C>
void workWithContainer(const C& container) { 
    auto calc1 = computeSomeValue1();
    auto calc2 = computeSomeValue2();

    auto divisor = computeDivisor(calc1, calc2);

    using ContElemT = typename C::value_type;
    using std::begin;
    using std::end;

    // C++11
    if (std::all_of(begin(container), end(container),
                [&](const ContElemT& value) {
                    return value % divisor == 0;
                }))
    {
        std::cout << "All elements" << std::endl;
    } 
    else {
        std::cout << "Not all elements" << std::endl;
    }

    // C++14
    if (std::all_of(begin(container), end(container),
                    [&](const auto& value) {
                        return value % divisor == 0;
                    }))
    {
        std::cout << "All elements [C++14]" << std::endl;
    }
    else {
        std::cout << "Not all elements [C++14]" << std::endl;
    }

}

int main() {
    std::vector<int> vector1 = { 1, 2, 3, 4, 5 };
    std::vector<int> vector2 = { 0,  2,  4 };

    workWithContainer(vector1);
    workWithContainer(vector2);

    return 0;

}

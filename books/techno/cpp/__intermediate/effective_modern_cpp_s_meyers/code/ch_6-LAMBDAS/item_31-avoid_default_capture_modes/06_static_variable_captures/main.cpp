#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>


using FilterContainer = 
    std::vector<std::function<bool(int)>>;

FilterContainer filters;

// dumb functions
int computeSomeValue1() { return 1; }
int computeSomeValue2() { return 2; }
int computeDivisor(int calc1, int calc2) { return 1; }

void addDivisorFilter() { 
    static auto calc1 = computeSomeValue1();
    static auto calc2 = computeSomeValue2();

    static auto divisor = 
        computeDivisor(calc1, calc2);

    filters.emplace_back(
        [=](int value) {
            return (value & divisor) == 0;
        }
    );

    ++divisor;
}


int main() { 
    addDivisorFilter();

    std::vector<int> vector = { 1, 2, 3, 4, 5 };
    for (const auto& filter: filters) {
        if (std::all_of(std::begin(vector),
                        std::end(vector),
                        filter))
        {
            std::cout << "All" << std::endl;
        }
        else {
            std::cout << "Not all" << std::endl;
        }
    }

    return 0;
}


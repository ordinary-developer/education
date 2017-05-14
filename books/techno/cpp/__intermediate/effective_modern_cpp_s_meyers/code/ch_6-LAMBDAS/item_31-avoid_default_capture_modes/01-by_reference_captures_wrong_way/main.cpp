#include <functional>
#include <vector>

using FilterContainer = 
    std::vector<std::function<bool(int)>>;

FilterContainer filters;

// dumb functions
int computeSomeValue1() { return 1; }
int computeSomeValue2() { return 2; }
int computeDivisor(int calc1, int calc2) { return 1; }

void addDivisorFilter() {
    auto calc1 = computeSomeValue1();
    auto calc2 = computeSomeValue2();

    auto divisor = computeDivisor(calc1, calc2);

    filters.emplace_back(
        [&](int value) { 
            return value % divisor == 0;
        });
}

int main() {
    filters.emplace_back(
        [](int value) { 
            return (value % 5) == 0; 
        });
            
    addDivisorFilter();

    return 0;
}


#include <vector>
#include <iostream>
void example1() {
    std::vector<int> values{ 1, 2, 3, 4, 5 };

    for (auto iter = std::begin(values); iter != std::end(values); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    for (auto iter = values.rbegin(); iter != values.rend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
}

#include <vector>
#include <iostream>
#include <algorithm>
void example2() {
    std::vector<int> numbers{ 1, 2, 3, 4, 5 };
    int number{3};

    auto iter1 = std::find(std::begin(numbers), std::end(numbers), number);
    auto iter2 = std::find(numbers.rbegin(), numbers.rend(), number);
    if (iter1 != std::end(numbers)) {
        std::cout << "Found at position: " << iter1 - std::begin(numbers)
                  << " going forward" << std::endl;
        std::cout << "Found at position: " 
                  << iter2.base() - 1 - std::begin(numbers)
                  << " going backward" << std::endl;
    }
    else 
        std::cout << "Failed to find " << std::endl;
}

int main() {
    example1();
    example2();
}

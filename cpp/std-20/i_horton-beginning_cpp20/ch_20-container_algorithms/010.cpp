#include <iostream>
#include <vector>

void printVector(const std::vector<int> & v)
{
    for (auto i : v)
        std::cout << i << ' ';
    std::cout << std::endl;
}

int main() {
    std::vector numbers{ 2, 4, 5}    ;
    numbers.insert(numbers.begin(), 1);
    printVector(numbers);

    numbers.insert(numbers.begin() + numbers.size() / 2, 3);
    printVector(numbers);

    std::vector moreNumbers{ 6, 7, 8 };
    numbers.insert(numbers.end(), moreNumbers.begin(), moreNumbers.end());
    printVector(numbers);

    numbers.erase(numbers.end() - 3, numbers.end());
    numbers.erase(numbers.begin() + numbers.size() / 2);
    numbers.erase(numbers.begin());
    printVector(numbers);
}

#include <iostream>
#include <string_view>
#include <vector>


void removeEvenNumbers(auto & numbers);
std::vector<int> fillVector_1toN(std::size_t N);
void printVector(std::string_view message, const std::vector<int> & numbers);


int main() {
    const std::size_t countOfNums{20};
    auto nums{ fillVector_1toN(countOfNums)};
    printVector("The original set of numbers", nums);

    removeEvenNumbers(nums);
    printVector("The numbers that were kept", nums);
    
    return 0;
}


void removeEvenNumbers(auto & numbers) {
    for (auto iter{numbers.begin()}; iter != numbers.end(); ) {
        if (*iter % 2 == 0)
            iter = numbers.erase(iter);
        else
            ++iter;
    }
}

std::vector<int> fillVector_1toN(std::size_t N) {
    std::vector<int> numbers;
    for (std::size_t i{1}; i <= N; ++i)
        numbers.push_back(i);
    return numbers;
}

void printVector(std::string_view message, const std::vector<int> & numbers) {
    std::cout << message << ": ";
    for (int number : numbers)
        std::cout << number << ' ';
    std::cout << std::endl;
}

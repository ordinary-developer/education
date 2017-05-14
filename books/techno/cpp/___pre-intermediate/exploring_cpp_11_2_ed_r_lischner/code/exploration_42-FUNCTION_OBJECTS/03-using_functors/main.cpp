#include "sequence.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    int size{};
    std::cout << "How many integers to you want? ";
    std::cin >> size;

    int first{};
    std::cout << "What it the first integer? ";
    std::cin >> first;
    int step{};
    std::cout << "What is the interval between successive integers? ";
    std::cin >> step;

    std::vector<int> data(size);
    std::generate(data.begin(), data.end(), sequence(first, step));

    std::copy(data.begin(),
              data.end(),
              std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}

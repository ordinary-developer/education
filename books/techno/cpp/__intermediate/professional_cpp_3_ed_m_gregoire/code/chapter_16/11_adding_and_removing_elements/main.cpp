#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>


template <typename T>
void printVector(const std::vector<T>& v) {
    for (auto& element : v) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

auto main() -> int {
    std::vector<int> vectorOne = { 1, 2, 3, 5 };
    std::vector<int> vectorTwo;

    vectorOne.insert(begin(vectorOne) + 3, 4);
    for (int i = 6; i <= 10; i ++) {
        vectorTwo.push_back(i);
    }
    printVector(vectorOne);
    printVector(vectorTwo);

    vectorOne.insert(end(vectorOne), begin(vectorTwo), end(vectorTwo));
    printVector(vectorOne);

    vectorTwo.clear();
    vectorTwo.insert(begin(vectorTwo), 10, 100);
    vectorTwo.pop_back();
    printVector(vectorTwo);

    return 0;
}

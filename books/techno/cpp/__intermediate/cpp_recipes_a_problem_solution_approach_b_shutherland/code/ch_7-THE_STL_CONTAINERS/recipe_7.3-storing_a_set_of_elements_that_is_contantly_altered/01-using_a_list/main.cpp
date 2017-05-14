#include <iostream>
#include <cstdint>
#include <list>

int main() {
    std::list<int32_t> myList{ 1, 2, 3, 4, 5 };

    myList.emplace_front(6);
    myList.emplace_back(7);

    auto forwardIter = myList.begin();
    ++forwardIter;
    ++forwardIter;
    myList.emplace(forwardIter, 9);

    auto reverseIter = myList.end();
    --reverseIter;
    --reverseIter;
    --reverseIter;
    myList.emplace(reverseIter, 8);

    for (auto&& number : myList)
        std::cout << number << std::endl;

    return 0;
}

#include <iostream>
#include <cstdint>
#include <forward_list>

int main() {
    std::forward_list<int32_t> myList{ 1, 2, 3, 4, 5 };

    myList.emplace_front(6);

    auto forwardIter = myList.begin();
    ++forwardIter;
    ++forwardIter;
    myList.emplace_after(forwardIter, 9);

    for (auto&& number : myList)
        std::cout << number << std::endl;

    return 0;
}

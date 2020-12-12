#include <algorithm>
#include <iostream>
#include <vector>

bool IsGreater(int left, int right) {
    return left > right;
}

int main() {
    std::vector<int> myVector{ 10, 6, 4, 7, 8, 3, 9 };
    std::sort(myVector.begin(), myVector.end(), IsGreater);

    for (auto&& element: myVector)
        std::cout << element << ", ";
    std::cout << std::endl;

    return 0;
}

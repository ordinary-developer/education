#include <algorithm>
#include <iostream>
#include <vector>


int main() {
    std::vector<int> myVector{ 4, 10, 6, 9, 1 };
    auto minimum = std::min_element(myVector.begin(), myVector.end());

    std::cout << "Minimum value: " << *minimum << std::endl;

    return 0;
}

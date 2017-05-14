#include <algorithm>
#include <iostream>
#include <vector>


int main() {
    std::vector<int> myVector{ 3, 2, 3, 7, 3, 8, 9, 3 };
    auto number = std::count(myVector.begin(), myVector.end(), 3);
    std::cout << "The number of 3s in myVector is: "
              << number << std::endl;

    return 0;
}

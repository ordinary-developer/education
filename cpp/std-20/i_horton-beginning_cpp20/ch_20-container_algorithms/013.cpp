#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>


int main(){
    std::vector nums{ 91, 18, 92, 22, 13, 43 };

    std::cout << "min element: " << *std::min_element(std::cbegin(nums), std::cend(nums)) << std::endl;
    std::cout << "max element: " << *std::max_element(std::cbegin(nums), std::cend(nums)) << std::endl;

    int numToSearchFor{};
    std::cout << "Please enter a number: ";
    std::cin >> numToSearchFor;

    auto nearer = [=](int x, int y) {
       return std::abs(x - numToSearchFor)  < std::abs(y - numToSearchFor);
    };

    std::cout 
        << "The number nearest to " << numToSearchFor << " is "
        << *std::min_element(std::cbegin(nums), std::cend(nums), nearer) << std::endl;

    std::cout
        << "The number furthest from " << numToSearchFor << " is "
        << *std::max_element(std::cbegin(nums), std::cend(nums), nearer) << std::endl;

    const auto [nearest, furthest] =
        std::minmax_element(std::cbegin(nums), std::cend(nums), nearer);
    std::cout
        << "the number nearest to " << numToSearchFor << " is "
        << *nearest << std::endl;
    std::cout
        << "The number furthest from " << numToSearchFor << " is "
        << *furthest << std::endl;
}

#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>


int main() {
    std::vector<int> data{ std::istream_iterator<int>(std::cin),
                           std::istream_iterator<int>() };
    std::sort(data.begin(), data.end());
    auto const& range(std::equal_range(data.begin(), data.end(), 42));
    if (range.first != range.second) {
        std::cout << "index of start of range: " 
                  << range.first - data.begin() << '\n';
        std::cout << "index of end of range: "
                  << range.second - data.begin() << '\n';
    }
    std::cout << "size of range: " << range.second - range.first 
              << '\n';

    return 0;
}

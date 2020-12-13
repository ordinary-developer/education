#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int main() {
    std::vector<int> data{};
    data.insert(data.begin(), std::istream_iterator<int>(std::cin),
                              std::istream_iterator<int>());
    std::sort(data.begin(), data.end());

    {
        std::cout << '{';
        std::string separator{" "};
        for (int element : data) {
            std::cout << separator << element;
            separator = ", ";
        }
        std::cout << " }\n";
    }

    return 0;
}

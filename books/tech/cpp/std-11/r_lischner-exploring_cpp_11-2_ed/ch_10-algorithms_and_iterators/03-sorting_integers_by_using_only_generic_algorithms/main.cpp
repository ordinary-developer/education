#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


int main() {
    std::vector<int> data{};

    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(data));

    std::sort(std::begin(data), std::end(data));

    std::copy(std::begin(data), std::end(data),
              std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}

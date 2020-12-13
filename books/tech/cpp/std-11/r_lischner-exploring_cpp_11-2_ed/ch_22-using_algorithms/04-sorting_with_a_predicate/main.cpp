#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


int descending(int a, int b) {
    return a > b;
}

int main() {
    std::vector<int> data{};

    data.insert(data.begin(),
                std::istream_iterator<int>(std::cin),
                std::istream_iterator<int>());

    std::sort(data.begin(), data.end(), descending);

    std::copy(data.begin(), 
              data.end(), 
              std::ostream_iterator<int>(std::cout, "\n"));
                              
    return 0;
}

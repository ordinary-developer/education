#include <iostream>
#include <iterator>
#include <vector>


int main() {
    std::vector<int> data{};
    data.insert(data.begin(),
                std::istream_iterator<int>(std::cin),
                std::istream_iterator<int>());
    std::vector<int>::iterator iter{}, end{ data.end() };
    for (iter = data.begin(); iter != end and 0 == *iter; ++iter)
        /*empty*/;
    if (data.end() == iter)
        std::cout << "data contains all zeroes\n";
    else
        std::cout << "data does not contain all zeroes\n";

    return 0;
}

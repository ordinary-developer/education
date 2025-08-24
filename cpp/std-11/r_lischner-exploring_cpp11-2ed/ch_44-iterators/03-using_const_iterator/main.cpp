#include <iostream>
#include <iterator>

#include "data.hpp"


int main() {
    intvector data{};
    read_data(data);
    intvector::const_iterator iter{ data.begin() };
    std::advance(iter, data.size() / 2);
    if (not data.empty())
        std::cout << "middle item = " << *iter << '\n';

    return 0;
}

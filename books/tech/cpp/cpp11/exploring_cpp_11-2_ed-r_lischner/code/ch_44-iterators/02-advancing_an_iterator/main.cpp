#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "data.hpp"
#include "sequence.hpp"


int main() {
    intvector data(10);
    std::generate(data.begin(), data.end(), sequence{ 0, 2 });
    intvec_iterator iter{ data.begin() };
    std::advance(iter, 4);
    std::cout << *iter << ", ";
    iter = std::prev(iter, 2);
    std::cout << *iter << '\n';

    return 0;
}

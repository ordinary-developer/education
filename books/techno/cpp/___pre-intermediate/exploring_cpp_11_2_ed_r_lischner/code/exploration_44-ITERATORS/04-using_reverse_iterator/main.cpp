#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>

#include "data.hpp"
#include "sequence.hpp"


int main() {
    intvector data(10);
    std::generate(data.begin(), data.end(), sequence(1));
    write_data(data);
    intvector::iterator iter{ data.begin() };
    iter = iter + 5;
    std::cout << *iter << '\n';

    intvector::reverse_iterator rev{ data.rbegin() };
    std::cout << *rev << '\n';
    rev = rev + 4;
    std::cout << *rev << '\n';
    std::cout << *rev.base() << '\n';
    std::cout << *data.rend().base() << '\n';
    assert(data.rbegin().base() == data.end());
    assert(data.rend().base() == data.begin());

    return 0;
}

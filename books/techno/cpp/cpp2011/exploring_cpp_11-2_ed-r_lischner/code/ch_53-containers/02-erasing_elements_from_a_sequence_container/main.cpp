#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <vector>

#include "erase_less.hpp"

template <class Container> 
void read(std::string const& str, Container& container) {
    std::istringstream in{ str };
    container.insert(container.begin(),
                     std::istream_iterator<typename Container::value_type>(in),
                     std::istream_iterator<typename Container::value_type>());
}

template <class Container>
void print(std::string const& label, Container const& container) {
    std::cout << label;
    std::copy(container.begin(),
              container.end(),
              std::ostream_iterator<typename Container::value_type>(std::cout,
                                                                    " "));
    std::cout << '\n';
}

void test(std::string const& str) {
    std::list<int> list{};
    read(str, list);
    print("before: ", list);
    erase_less(list);
    print("after: ", list);

    std::vector<int> vector{};
    read(str, vector);
    erase_less(vector);

    assert(list.size() == vector.size());
    assert(std::equal(list.begin(), list.end(), vector.begin()));
}

int main() {
    test("2 3 7 11 13 17 23 29 31 37");
    test("37 31 29 23 17 13 11 7 3 2");
    test("");
    test("42");
    test("10 30 20 40 0 50");

    return 0;
}

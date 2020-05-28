#include "advance.hpp"

#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <ostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> vector{ 10, 20, 30, 40 };
    std::vector<int>::iterator vector_iterator{ vector.begin() };
    my_advance(vector_iterator, 2);

    std::list<int> list(vector.begin(), vector.end());
    std::list<int>::iterator list_iterator{ list.begin() };
    my_advance(list_iterator, 2);

    std::ifstream file{"advance.hpp"};
    if (file) {
        std::istream_iterator<std::string> file_iterator{file};
        my_advance(file_iterator, 2);
    }

    return 0;
}

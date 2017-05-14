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

    for (std::vector<int>::iterator iter{ data.begin() },
                                    end{ data.end() };
         iter != end; )
    {
        int value{ *iter };
        std::vector<int>::iterator 
            here{ std::lower_bound(data.begin(), iter, value) };
        if (iter == here)
            ++iter;
        else {
            iter = data.erase(iter);
            data.insert(here, value);
        }
    }

    for (std::vector<int>::iterator iter{ data.begin() },
                                    prev{ data.end() },
                                    end{ data.end() };
         iter != end;
         ++iter)
    {
        if (prev != data.end())
            assert(not (*iter < *prev));
        prev = iter;
    }

    std::cout << '{';
    std::string separator{ " " };
    for (int element : data) {
        std::cout << separator << element;
        separator = ", ";
    }
    std::cout << " }\n";

    return 0;
}

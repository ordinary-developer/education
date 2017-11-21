#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

#include "data.hpp"
#include "randomint.hpp"


int main() {
    intvector pi{ 3, 1, 4, 1 };
    intvector data(10000);

    std::generate(data.begin(), data.end(), randomint{ 0, 9 });

    auto iter(std::search(data.begin(), 
                          data.end(), 
                          pi.begin(), 
                          pi.end()));
    if (data.end() == iter)
        std::cout << 
            "The integer range does not contain the digits pi.\n";
    else {
        std::cout << "Easy as pi: ";
        std::copy(iter, 
                  iter + pi.size(), 
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }

    return 0;
}

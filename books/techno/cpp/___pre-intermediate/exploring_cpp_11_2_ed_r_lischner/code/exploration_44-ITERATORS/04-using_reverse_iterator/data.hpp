#ifndef DATA_HPP_
#define DATA_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

typedef std::vector<int> intvector;
typedef intvector::iterator intvec_iterator;


inline void read_data(intvector& data) {
    data.clear();
    data.insert(data.begin(), 
                std::istream_iterator<int>(std::cin),
                std::istream_iterator<int>());
}

inline void write_data(intvector const& data) {
    std::cout << "{ ";
    std::copy(data.begin(), 
              data.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "}\n";
}

#endif

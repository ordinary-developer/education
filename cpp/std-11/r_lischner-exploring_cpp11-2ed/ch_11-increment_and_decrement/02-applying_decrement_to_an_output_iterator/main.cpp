#include <iostream>
#include <iterator>
#include <vector>


int main() {
    std::vector<int> data{ 10, 42 };
    std::ostream_iterator<int> 
        out{ std::ostream_iterator<int>( std::cout, "") };
    std::copy(std::begin(data), std::end(data), out);

    // here a compilation error will be
    //--out;

    return 0;
}

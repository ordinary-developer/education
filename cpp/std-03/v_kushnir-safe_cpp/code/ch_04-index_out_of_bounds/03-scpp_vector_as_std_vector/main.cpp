#define SCPP_TEST_ASSERT_ON

#include "scpp_vector.hpp"

#include <vector>
#include <iostream>
void FunctionTakingRefToSTLVector(const std::vector<int>& v) {
    std::cout << "ATTENTION, we are about to test index-of-bounds "
              << "for STL vector reference to scpp::vector"
              << std::endl << std::flush;

    for (unsigned int i = 0; i <= v.size(); ++i) 
        std::cout << "Value of vector at " << i 
                  << " is " << v[i] << std::endl;
}

int main() {
    scpp::vector<int> v;
    for (unsigned int i = 0; i < 3; ++i) 
        v.push_back(i);
    std::cout << "Initial vector: " << v << std::endl;

    FunctionTakingRefToSTLVector(v);

    return 0;
}

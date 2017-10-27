#define SCPP_TEST_ASSERT_ON

#include <iostream>
#include "scpp_vector.hpp"


int main() {
    scpp::vector<int> vect;
    for (int i = 0; i < 3; ++i)
        vect.push_back(i);

    std::cout << "My vector = " << vect << std::endl;

    for (unsigned int i = 0; i <= vect.size(); ++i)
        std::cout << "Value of vector at " << i << " is " 
                  << vect[i] << std::endl;

    return 0;
}

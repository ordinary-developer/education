#include <vector>


int main() {
    // use the non-std::initializer_list constructor
    // create a 10-element std::vector, all elements have value of 20
    std::vector<int> v1(10, 20);

    // use the std::initializer_list constructor
    // create a two element std::vector, elements values are 10 and 20
    std::vector<int> v2{ 10, 20 };
}

#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    using IntVector = std::vector<int32_t>;
    using IntVectorIterator = IntVector::iterator;
    using ConstIntVectorIterator = IntVector::const_iterator;

    IntVector myVector(5, 0);
    int32_t value{ 0 };
    for (IntVectorIterator iter{ myVector.begin() } ;
         iter != myVector.end(); 
         ++iter)
    {
        *iter = value++;
    }

    for (ConstIntVectorIterator iter{ myVector.cbegin() } ;
         iter != myVector.cend(); 
         ++iter)
    {
        std::cout << "The value is: " << *iter << std::endl;
    }

    return 0;
}

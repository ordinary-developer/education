#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    using IntVector = std::vector<int32_t>;

    using IntVectorIterator = IntVector::iterator;
    using ConstIntVectorIterator = IntVector::const_iterator;

    using ReverseIntVectorIterator = IntVector::reverse_iterator;
    using ConstReverseIntVectorIterator =
        IntVector::const_reverse_iterator;


    IntVector myVector(5, 0);
    int32_t value{ 0 };
    for (IntVectorIterator iter{ myVector.begin() } ;
         iter != myVector.end(); 
         ++iter)
    {
        *iter = value++;
    }

    for (ConstReverseIntVectorIterator iter{ myVector.crbegin() } ;
         iter != myVector.crend(); 
         ++iter)
    {
        std::cout << "The value is: " << *iter << std::endl;
    }

    return 0;
}

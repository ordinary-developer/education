#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    using IntVector = std::vector<int32_t>;
    using IntVectorIterator = IntVector::iterator;

    IntVector myVector{ 0, 1, 2, 3, 4 };
    for (IntVectorIterator iter{ myVector.begin() } ;
         iter != myVector.end(); 
         ++iter)
    {
        std::cout << "The value is: " << *iter << std::endl;
    }

    return 0;
}

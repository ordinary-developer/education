#include <atomic>
#include <iostream>

#include <cassert>


int main() 
{
    int intArray[5];
    std::atomic<int*> p{intArray};

    p++;
    assert(p.load() == &intArray[1]);

    p += 1;
    assert(p.load() == &intArray[2]);

    --p;
    assert(p.load() == &intArray[1]);
}

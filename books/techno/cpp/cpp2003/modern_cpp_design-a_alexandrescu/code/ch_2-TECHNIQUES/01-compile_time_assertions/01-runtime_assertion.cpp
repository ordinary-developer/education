#include <iostream>
#include <cassert>


template <class To, class From>
To safe_reinterpret_cast(From from) 
{
    assert(sizeof(From) <= sizeof(To));
    return reinterpret_cast<To>(from);
}


int main() {
    int i = 5;
    char* p = safe_reinterpret_cast<char*>(i);

    return 0;
}

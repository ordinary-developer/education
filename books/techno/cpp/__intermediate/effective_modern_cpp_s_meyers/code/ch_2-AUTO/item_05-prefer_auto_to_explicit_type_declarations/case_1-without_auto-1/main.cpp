#include <iostream>

template <typename It>
void dwim(It b, It e)
{
    while (b != e) {
        typename std::iterator_traits<It>::value_type currValue = *b;
    }
}

int main() {
    // an uninitialized value
    // may be it will be zero but not necessarily
    int x;
    std::cout << x << std::endl;
}

#include <iostream>

template <typename It>
void dwim(It b, It e)
{
    while (b != e) {
        typename std::iterator_traits<It>::value_type currValue = *b;
    }
}

int main() {
}

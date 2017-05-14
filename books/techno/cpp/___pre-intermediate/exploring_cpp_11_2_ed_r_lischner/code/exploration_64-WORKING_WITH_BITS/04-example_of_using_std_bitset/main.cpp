#include <bitset>
#include <cstdlib>
#include <iostream>
#include <string>


template <std::size_t N>
std::size_t first(std::bitset<N> const&  bitset) {
    for (std::size_t i{bitset.size()}; 0 != i--; /*empty*/)
        if (bitset.test(i))
            return i;
    return std::size_t(-1);
}

int main() {
    std::bitset<50> lots_of_bits{ std::string{"1011111100111111000111"} };
    std::cout << "bitset: " << lots_of_bits << '\n';
    std::cout << "first 1 bit: " << first(lots_of_bits) << '\n';
    std::cout << "count of 1 bits: " << lots_of_bits.count() << '\n';
    lots_of_bits[first(lots_of_bits)] = false;
    std::cout << "new first 1 bit: " << first(lots_of_bits) << '\n';
    lots_of_bits.flip();
    std::cout << "bitset: " << lots_of_bits << '\n';
    std::cout << "first 1 bit: " << first(lots_of_bits) << '\n';

    return 0;
}

#include <iostream>
#include <vector>


int main() {
    std::vector letters{ 'a', 'b', 'c', 'e' };
    auto myIter{ letters.begin() };

    std::vector<char>::iterator myIter2{ letters.begin() };

    std::cout << *myIter << std::endl;

    *myIter = 'x';
    std::cout << letters[0] << std::endl;

    ++myIter;
    std::cout << *myIter << std::endl;

    myIter += 2;
    std::cout << *myIter-- << std::endl;
    std::cout << *myIter << std::endl;

    auto copy{ myIter };
    myIter += 2;
    std::cout << *copy << std::endl;
    std::cout << *myIter << std::endl;
    std::cout << myIter - copy << std::endl;
}

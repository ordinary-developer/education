#include <vector>
#include <cstddef>
#include <iostream>
namespace example01 {
void run() {
    std::vector<int> integers{ 2, 5, 8, 22, 45, 67, 99 };

    std::size_t leftIndex{0};
    std::size_t rightIndex{ integers.size() - 1 };
    while (leftIndex < rightIndex) {
        int buffer{ integers[rightIndex] };
        integers[rightIndex] = integers[leftIndex];
        integers[leftIndex] = buffer;
        ++leftIndex;
        --rightIndex;
    }

    for (auto const& element : integers)
        std::cout << element << " ";
    std::cout << std::endl;
}
}

#include <algorithm>
#include <vector>
#include <string>
namespace example02 {
void run() {
    std::vector<int> vectorOfIntegers{ 2, 5, 8, 22, 45, 67, 99 };
    std::reverse(std::begin(vectorOfIntegers), std::end(vectorOfIntegers));
    for (auto const& element : vectorOfIntegers)
        std::cout << element << " ";
    std::cout << std::endl;

    int arrayOfIntegers[] = { 2, 5, 8, 22, 45, 67, 99 };
    std::reverse(std::begin(arrayOfIntegers), std::end(arrayOfIntegers));
    for (auto const& element : arrayOfIntegers)
        std::cout << element << " ";
    std::cout << std::endl;

    std::string text1{ "The big brown fox jumps over the lazy dog!" };
    std::reverse(std::begin(text1), std::end(text1));
    std::cout << text1 << std::endl;

    std::string text2{ "The big brown fox jumps over the lazy dog!" };
    std::reverse(std::begin(text2) + 13, std::end(text2) - 9);
    std::cout << text2 << std::endl;
}
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
namespace example03 {

void printCommaSeparated(std::string const& text) {
    std::cout << text << ", ";
}

void run() {
    std::vector<std::string> names{ "Peter", "Harry", "Julia", 
                                    "Marc", "Antonio", "Glenn" };
    std::sort(std::begin(names), std::end(names));
    std::for_each(std::begin(names), std::end(names), printCommaSeparated);
    std::cout << std::endl;
}
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
namespace example04 {
void run() {
    std::vector<std::string> const names1{ "Peter", "Harry", "Julia",
                                           "Marc", "Antonio", "Glenn" };
    std::vector<std::string> const names2{ "Peter", "Harry", "Julia",
                                           "Marc", "Antonio", "Glenn" };

    bool const isEqual = std::equal(std::begin(names1), std::end(names1),
                                    std::begin(names2), std::end(names2));
    
    if (isEqual)
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";
}
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
namespace example05 {

bool compareFirstThreeCharactersOnly(std::string const& string1,
                                    std::string const& string2)
{
    return 0 == string1.compare(0, 3, string2, 0, 3);
}

void run() {
    std::vector<std::string> const names1{ "Peter", "Harry", "Julia",
                                           "Marc", "Antonio", "Glenn" };
    std::vector<std::string> const names2{ "Peter", "Harold", "Julia",
                                           "Maria", "Antonio", "Glenn" };

    bool const isEqual = 
        std::equal(std::begin(names1),
                   std::end(names1),
                   std::begin(names2),
                   std::end(names2),
                   compareFirstThreeCharactersOnly);

    if (isEqual)
        std::cout << "The first three characters of all strings "
                      "in both sequences are equal.\n";
    else
        std::cout << "The first three characters of all strings " 
                      "in both sequences differ.\n";
}
}

int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();

    return 0;
}

#include <cstddef>
#include <iostream>
namespace example1 {

using MatchFunc = bool(*)(int, int);
typedef bool(*MatchFuncAux)(int, int);

void findMatches(int values1[], 
                 int values2[],
                 size_t numValues,
                 MatchFunc inFunc)
{
    for (size_t i{0}; i < numValues; ++i)
        if (inFunc(values1[i], values2[i]))
            std::cout << "Match found at position " << i 
                      << " (" << values1[i] << ", " << values2[i] << " )"
                      << std::endl;
}

bool intEqual(int inItem1, int inItem2) { return inItem1 == inItem2; }

bool bothOdd(int inItem1, int inItem2) {
    return 1 == inItem1 % 2  and 1 == inItem2 % 2;
}

void run() {
    int numbers1[] = { 2, 5, 6, 9, 10, 1, 1 };
    int numbers2[] = { 4, 4, 2, 9, 0, 3, 4 };
    
    size_t size{ sizeof(numbers1) / sizeof(numbers1[0]) };

    std::cout << "Calling findMatches() using intEqual():" << std::endl;
    findMatches(numbers1, numbers2, size, &intEqual);
    findMatches(numbers1, numbers2, size, intEqual);

    std::cout << "Calling findMatches() using bothOdd():" << std::endl;
    findMatches(numbers1, numbers2, size, &bothOdd);
    findMatches(numbers1, numbers2, size, bothOdd);
}

} // end of example1 namespace

int main() {
    example1::run();

    return 0;
}

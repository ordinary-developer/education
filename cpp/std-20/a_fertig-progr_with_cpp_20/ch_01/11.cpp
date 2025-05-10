#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
#include <cassert>
namespace example_01 {

template <typename T>
void PrintSorted(T c)
{
    std::sort(c.begin(), c.end());

    for (const auto& e : c) {
        std::cout << e << ' ';
    }

    std::cout << '\n';
}

void sortedVector() {
    std::vector<int> v{30, 4, 22, 5};

    PrintSorted(v);
}

void run() {
    std::cout << "[ ok ] example 01" << std::endl;
    sortedVector();

}

} // example_01



#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <type_traits>
#include <vector>
namespace example_02 {

template <typename T>
concept HasSortMethod = requires(T t)
{
    t.sort();
};

template <HasSortMethod T>
void PrintSorted(T c)
{
    c.sort();

    for (const auto& e : c) {
        std::cout << e << " ";
    }

    std::cout << '\n';
}

void sortedVector() {
    std::vector<int> v{30, 4, 22, 5};

    // an error will be here
    //PrintSorted(v);
}

void run() {
    std::cout << "[ ok ] example 02" << std::endl;
}

} // example_02



int main() {
    example_01::run();
    example_02::run();
}
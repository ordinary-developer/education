#include <vector>
#include <iterator>
#include <iostream>
namespace example1 {
template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator find_all(InputIterator first,
                        InputIterator last,
                        OutputIterator dest,
                        Predicate predicate)
{
    while (first != last) {
        if (predicate(*first)) {
            *dest = first;
            ++dest;
        }
        ++first;
    }

    return dest;
}

void run() {
    std::vector<int> src{ 3, 4, 5, 4, 5, 6, 5, 8 };
    std::vector<std::vector<int>::iterator> matches{};
    find_all(std::begin(src), 
             std::end(src),
             std::back_inserter(matches),
             [](int i) { return 5 == i; });
    std::cout << "Found " << matches.size() 
              << " matching elements: " << std::endl;
    for (auto iter : matches)
        std::cout << *iter << " at position " << (iter - src.cbegin())
                  << std::endl;
}
}

int main() {
    example1::run();

    return 0;
}

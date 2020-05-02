// #region example1
#include <iterator>
#include <iostream>
#include <vector>
namespace example1 {

template <typename IteratorType>
void iteratorTraitsTest(IteratorType iter) {
    typename std::iterator_traits<IteratorType>::value_type tmp{};
    tmp = *iter;
    std::cout << tmp << std::endl;
}

void run() {
    std::vector<int> v{ 5 };
    iteratorTraitsTest(v.cbegin());
}

}
// #endregion example1


int main() {
    example1::run();

    return 0;
}

#include <concepts>
#include <iostream>
#include <iterator>
#include <functional>
#include <list>
#include <string>
#include <vector>

#include <cassert>


template <typename Iterator, typename Comparison>
Iterator find_optimum_impl(Iterator begin, Iterator end, Comparison compare) {
    if (begin == end)
        return end;

    Iterator optimum{ begin };
    for (Iterator iter{ ++begin }; iter != end; ++iter)
        if (compare(*iter, *optimum))
            optimum = iter;

    return optimum;
}


template <typename Iterator, typename Comparison>
Iterator find_optimum_01(Iterator begin, Iterator end, Comparison compare) { 
    return find_optimum_impl(begin, end, compare);
}

template <
    std::forward_iterator Iterator,
    std::indirect_strict_weak_order<Iterator> Comparison
>
Iterator find_optimum_02(Iterator begin, Iterator end, Comparison compare) {
    return find_optimum_impl(begin, end, compare);
}

//template <
//    std::forward_iterator Iterator,
//    std::strict_weak_order<std::iter_reference_t<Iterator>> Comparison
//>
//Iterator find_optimum_03(Iterator begin, Iterator end, Comparison compare) {
//    return find_optimum_impl(begin, end, compare);
//}


int main() {
    std::vector<int> vals{ 1, 2, 3, 4, 5 };
    
    std::cout 
        << "1: "
        << *(find_optimum_01(std::cbegin(vals), std::cend(vals), std::greater<int>{}))
        << std::endl;
    
    std::cout 
        << "2: "
        << *(find_optimum_02(std::cbegin(vals), std::cend(vals), std::greater<int>{}))
        << std::endl;
    
//    std::cout 
//        << "3: "
//        << *(find_optimum_03(vals.begin(), vals.end(), std::greater<int>{}))
//        << std::endl;
    
    assert(true);
}

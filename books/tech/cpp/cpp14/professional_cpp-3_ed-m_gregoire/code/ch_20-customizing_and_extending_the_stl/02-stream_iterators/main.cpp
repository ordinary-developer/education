#include <vector>
#include <numeric>
#include <iterator>
#include <iostream>
void example1() {
    std::vector<int> numbers(10);
    std::iota(std::begin(numbers), std::end(numbers), 1);
    std::copy(numbers.cbegin(), 
              numbers.cend(), 
              std::ostream_iterator<int>(std::cout, " "));
}


#include <iostream>
#include <iterator>
#include <algorithm>
void example2() {
    std::cout << "Enter numbers separated by white space." << std::endl;
    std::cout << "Press Ctrl+Z followed by Enter to stop." << std::endl;
    std::istream_iterator<int> numbersIter{ std::cin };
    std::istream_iterator<int> endIter{};
    int sum{ accumulate(numbersIter, endIter, 0) };
    std::cout << "Sum: " << sum << std::endl; 
}

int main() {
    example1();
    example2();

    return 0;
}

#include <list>
#include <algorithm>
#include <iostream>

template <typename T>
std::list<T> sequential_quick_sort(std::list<T> input) {
    if (input.empty()) {
        return input;
    }

    std::list<T> result;
    result.splice(result.begin(), input, input.begin());
    const T& pivot = *result.begin();

    auto divide_point = std::partition(input.begin(), input.end(),
            [&](const T& t) { return t < pivot; });
    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, input.begin(),
                      divide_point);

    auto new_lower(sequential_quick_sort(std::move(lower_part)));
    auto new_higher(sequential_quick_sort(std::move(input)));
    result.splice(result.end(), new_higher);
    result.splice(result.begin(), new_lower);

    return result;
}


int main() {
    std::list<unsigned int> list = { 2, 1, 10, 9, 8, 7, 6, 5 };
    auto sortedList = sequential_quick_sort(list);

    std::cout << "[Unsorted list]" << std::endl;
    for(auto const& element : list) {
        std::cout << element << "\t";
    }
    std::cout << std::endl;

    std::cout << "[Sorted list]" << std::endl;
    for (auto const& element : sortedList) {
        std::cout << element << "\t";
    }
    std::cout << std::endl;

    return 0;
}


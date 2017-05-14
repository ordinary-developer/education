#include <list>
#include <future>
#include <algorithm>
#include <iostream>

template <typename T>
std::list<T> parallel_quick_sort(std::list<T> input) {
    if (input.empty()) {
        return input;
    }

    std::list<T> result;

    result.splice(result.begin(), input, input.begin());
    const T& pivot = *result.begin();
    auto divide_point = std::partition(input.begin(), input.end(),
                                       [&](const T& t) {
                                           return t < pivot;
                                       });

    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, input.begin(),   
                      divide_point);

    std::future<std::list<T>> new_lower(
        std::async(&parallel_quick_sort<T>, std::move(lower_part)));

    auto new_higher(parallel_quick_sort(std::move(input)));

    result.splice(result.end(), new_higher);
    result.splice(result.begin(), new_lower.get());

    return result;
}

int main() {
    std::list<unsigned int> unsortedList = { 5, 4, 3, 2, 1 };
    std::cout << "[Unsorted list]" << std::endl;
    for (const auto& element : unsortedList) {
        std::cout << element << "\t";
    }
    std::cout << std::endl;

    auto sortedList = parallel_quick_sort(unsortedList);
    std::cout << "[Sorted list]" << std::endl;
    for (const auto& element : sortedList) {
        std::cout << element << "\t";
    }
    std::cout << std::endl;

    return 0;
}



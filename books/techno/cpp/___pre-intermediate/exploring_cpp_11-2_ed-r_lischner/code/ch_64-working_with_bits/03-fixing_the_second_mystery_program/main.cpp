#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <class InputIter>
typename std::iterator_traits<InputIter>::difference_type
index_of(InputIter first,
         InputIter last,
         typename std::iterator_traits<InputIter>::value_type const& value)
{
    InputIter iter{ std::find(first, last, value) };
    return (last == iter) ? -1 : std::distance(first, iter);
}

template <class T>
bool is_last(T const& container, typename T::value_type const& value)
{
    typename T::difference_type pos = index_of(container.begin(),
                                               container.end(),
                                               value);
    const auto last_index = 
        static_cast<typename T::difference_type>(container.size() - 1);

    return -1 != pos and last_index != pos;
}

int main() {
    std::vector<int> data{};
    if (is_last(data, 10))
        std::cout << "10 is the last item in data\n";

    std::vector<int> data2{ 10, 11, 12, 13, 14, 15 };
    std::cout << std::distance(std::end(data2), std::begin(data2));
    return 0;
}

#include <iostream>
#include <concepts>
#include <ranges>
#include <functional>
#include <iterator>
#include <vector>

#include <cassert>

using namespace std::ranges::views;


template <std::forward_iterator Iterator,
          std::indirect_strict_weak_order<Iterator> Comparison>
Iterator original_find_optimum(Iterator begin, Iterator end, Comparison compare)
{
    if (begin == end)
        return end;

    Iterator optimum{ begin };
    for (auto iter{ ++begin }; iter != end; ++iter)
        if (compare(*iter, *optimum))
            optimum = iter;

    return optimum;
}

template <
    std::forward_iterator Iterator,
    std::sentinel_for<Iterator> Sentinel,
    typename Projection = std::identity,
    std::indirect_strict_weak_order<std::projected<Iterator, Projection>> Comparison = std::ranges::less
>
Iterator find_optimum(Iterator begin, Sentinel end, Comparison compare = {}, Projection projection = {}) {
    if (begin == end)    
        return begin;

    Iterator optimum{ begin };
    for (auto iter{ ++begin }; iter != end; ++iter) 
        if (std::invoke(compare, std::invoke(projection, *iter), std::invoke(projection, *optimum)))
            optimum = iter;

    return optimum;
}
        

class Box {
public:
    Box() : Box{ 1, 1, 1 } {}
    Box(double length, double width, double height)
        : m_length{ length }, m_width{ width }, m_height{ height }
    {}

    double volume() const { return m_length * m_width * m_height; }
    double isSmallerThan(const Box & other) const { return volume() < other.volume(); }

private:
    double m_length, m_width, m_height;
};


int main() {
    std::vector<Box> boxes{ { 2.0, 2.0, 3.0 }, { 1.0, 3.0, 2.0 }, { 1.0, 2.0, 1.0 }, { 2.0, 3.0, 3.0} };

    auto firstBoxes{ boxes | std::ranges::views::take_while([](const Box & box) { return box.volume() < 15; })};
    //std::cout << "Volume of smallest box: "
    //    << original_find_optimum(firstBoxes.begin(), firstBoxes.end(),
    //        [](const Box & box1, const Box & box2) { return box1.isSmallerThan(box2); })->volume()
    //    << std::endl;    

    auto commonBoxes{ firstBoxes | std::ranges::views::common };
    std::cout << "Volume of smallest box: "
        << original_find_optimum(commonBoxes.begin(), commonBoxes.end(),
            [](const Box & box1, const Box & box2) { return box1.isSmallerThan(box2); })->volume()
        << std::endl;

    std::cout 
        << "Volume of smallest box (ex): "
        << original_find_optimum(
            std::cbegin(commonBoxes), 
            std::cend(commonBoxes),
            [](const Box & box1, const Box & box2) {
                return box1.isSmallerThan(box2);
            })->volume()
        << std::endl;

    std::cout 
        << "Volume of largest box: "
        << find_optimum(
            std::cbegin(firstBoxes),
            std::cend(firstBoxes),
            [](const Box & box1, const Box & box2) {
                return not box1.isSmallerThan(box2); 
            })->volume()
        << std::endl;

    std::cout 
        << "Volume of smallest box: "
        << find_optimum(
            std::cbegin(firstBoxes),
            std::cend(firstBoxes),
            &Box::isSmallerThan)->volume()
        << std::endl;

    std::cout
        << "Volume of largest box: "
        << find_optimum(
            std::cbegin(firstBoxes),
            std::cend(firstBoxes),
            std::greater<>{},
            &Box::volume)->volume()
        << std::endl;
    
    assert(true);
}

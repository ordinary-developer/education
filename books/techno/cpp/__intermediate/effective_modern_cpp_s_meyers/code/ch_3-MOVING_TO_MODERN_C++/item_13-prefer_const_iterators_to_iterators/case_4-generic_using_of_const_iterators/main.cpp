#include <algorithm>
// c++11 implementation
/*
template <class C>
auto cbegin(const C& container) -> decltype(std::begin(container))
{
    return std::begin(container);
}

template <class C>
auto cend(const C& container) -> decltype(std::end(container))
{
    return std::end(container);
}
*/
template <typename C, typename V>
void findAndInsert(C& container, 
                   const V& targetVal, const V& insertVal)
{
    // my comiler if very old
    // supporting only for c++14
    // auto it = std::find(std::cbegin(container), 
    //                     std::cend(container), targetVal);
     auto it = std::find(cbegin(container), 
                         cend(container), targetVal);
    container.insert(it, insertVal);
}

int main() {
}

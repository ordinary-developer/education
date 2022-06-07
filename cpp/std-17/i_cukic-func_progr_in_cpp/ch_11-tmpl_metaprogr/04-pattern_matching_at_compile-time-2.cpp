#include <numeric>
#include <vector>
#include <type_traits>
#include <cassert>
namespace workspace {
    
template <typename T>
struct my_remove_reference {
    using type = T;
};
    
template <typename T>
struct my_remove_reference<T&> {
    using type = T;
};

template <typename T>
struct my_remove_reference<T&&> {
    using type = T;
};
    
template <typename T>
using my_remove_reference_t =
    typename my_remove_reference<T>::type;
    
template <typename T>
using contained_type_t = 
    my_remove_reference_t<decltype(*begin(std::declval<T>()))>;

    
template <typename C,
          typename R = contained_type_t<C>>
R sum_iterable(C const& collection) {
    return std::accumulate(begin(collection), end(collection), R{});
}


void run() {
    assert(15 == sum_iterable(std::vector<int>{ 1, 2, 3, 4, 5 }));
}

} // workspace 


int main() {
    workspace::run();
}

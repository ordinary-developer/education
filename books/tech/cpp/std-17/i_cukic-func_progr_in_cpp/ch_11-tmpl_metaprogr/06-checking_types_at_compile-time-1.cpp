#include <iostream>
#include <numeric>
#include <type_traits>
#include <vector>
#include <cassert>
namespace workspace {

template <typename...>
using void_t = void;

template <typename C,
          typename = void_t<>>
struct has_value_type : std::false_type {};

template <typename C>
struct has_value_type<C, void_t<typename C::value_type>> : std::true_type {};

template <typename T>
using contained_type_t = 
    std::remove_cv_t<
        std::remove_reference_t<decltype(*begin(std::declval<T>()))>>;

template <typename C,
          typename R = contained_type_t<C>>
R sum_iterable(C const& collection) {
    return std::accumulate(std::begin(collection), std::end(collection), R());
}

template <typename C,
          typename R = typename C::value_type>
R sum_collection(C const& collection) {
    return std::accumulate(begin(collection), end(collection), R{});
}

template <typename C>
auto sum(C const& collection) {
    if constexpr (has_value_type<C>()) {        
        return sum_collection(collection);
    }
    else {        
        return sum_iterable(collection);
    }
}

void run() {
    assert(15 == sum(std::vector<int>{ 1, 2, 3, 4, 5 }));
    assert(15 == sum(std::initializer_list<int>{ 1, 2, 3, 4, 5 }));    
}

} // workspace


int main() {
    workspace::run();    
}
#include <iostream>
#include <numeric>
#include <type_traits>
#include <list>
#include <string>
#include <vector>
namespace workspace {
    
template <typename T>
using contained_type_t = 
    std::remove_cv_t<
        std::remove_reference_t<decltype(*begin(std::declval<T>()))>>;

template <typename C,
          typename R = contained_type_t<C>>
R sum(C const& collection) {
    return std::accumulate(std::begin(collection), std::end(collection), R());
}

void run() {
    auto const ret = sum(std::vector<int>{ 1, 2, 3, 4, 5 });
    std::cout << ret << std::endl;
}     

} // workspace 


int main() {
    workspace::run();
}

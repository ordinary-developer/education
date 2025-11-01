#include <numeric>
#include <vector>
#include <type_traits>
#include <cassert>
namespace workspace {
    
template <typename C,
          typename R = typename C::value_type>
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

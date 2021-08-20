#include <type_traits>
#include <string>

namespace workspace {

template <typename T1, typename T2>
struct my_is_same : std::false_type{};
    
template <typename T>
struct my_is_same<T, T> : std::true_type{};
    
void run() {
    static_assert(my_is_same<int, int>{},
        "int and int are the same");
    
    static_assert(not my_is_same<int, std::string>{},
        "int and std::string are not the same");
}

} // workspace 


int main() {
    workspace::run();
}

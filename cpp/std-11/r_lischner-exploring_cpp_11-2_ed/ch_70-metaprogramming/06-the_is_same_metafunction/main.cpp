#include <type_traits>

template <class T, class U>
struct is_same : std::false_type { };

template <class T>
struct is_same<T, T> : std::true_type { };

int main() {
    static_assert(is_same<int, int>(), "types are not same");
    static_assert(not is_same<int, unsigned int>(), "types are same");

    return 0;
}

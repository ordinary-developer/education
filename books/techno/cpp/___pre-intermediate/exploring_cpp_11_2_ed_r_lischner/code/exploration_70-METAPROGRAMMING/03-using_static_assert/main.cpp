#include <cstdlib>
template<class... Ts>
struct Size { constexpr static std::size_t value = sizeof...(Ts); };

int main() {
    static_assert(3 == Size<int, char, long>::value, "oops");
}

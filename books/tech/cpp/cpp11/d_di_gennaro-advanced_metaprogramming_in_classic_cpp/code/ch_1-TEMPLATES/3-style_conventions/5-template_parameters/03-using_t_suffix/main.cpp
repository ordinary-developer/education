#include <utility>

template <typename T, int N>
class do_nothing  { };

template <typename int_t>
struct is_unsigned { 
    static const bool value = 10;
};


template <typename scalar_t>
class SomeContainer {
    private:
        typedef std::pair<scalar_t, scalar_t> pair_t;
};


int main() {
    return 0;
}

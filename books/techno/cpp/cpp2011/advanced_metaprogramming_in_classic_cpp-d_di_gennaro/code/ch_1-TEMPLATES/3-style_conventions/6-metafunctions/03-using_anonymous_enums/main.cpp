#include <cstddef>
#include <algorithm>


template <size_t A>
struct is_prime {
    enum { value = 0 };
};

template <>
struct is_prime<2> {
    enum { value = 1 };
};

template <>
struct is_prime<3> {
    enum { value = 1 };
};



int main() {
    double data[10];

    // may be an error here
    std::fill_n(data, is_prime<3>::value, 3.14);
    // a better approach
    std::fill_n(data, int(is_prime<3>::value), 3.14);

    return 0;
}

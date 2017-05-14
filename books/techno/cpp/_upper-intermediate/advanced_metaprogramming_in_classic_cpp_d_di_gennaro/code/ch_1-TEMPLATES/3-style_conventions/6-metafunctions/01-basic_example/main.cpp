#include <cstddef>


template <typename T, int N>
struct F {
    typedef T* pointer_type;
    typedef T& reference_type;

    static const size_t value = sizeof(T) * N;
};


int main() {
    return 0;
}

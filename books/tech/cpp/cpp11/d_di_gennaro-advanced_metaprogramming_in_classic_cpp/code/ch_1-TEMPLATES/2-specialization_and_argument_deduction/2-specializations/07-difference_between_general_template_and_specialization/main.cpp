#include <algorithm>
#include <iostream>

template <typename T, int N>
struct base_with_array {
    T data_[N];

    void fill(const T& x) {
        std::cout << "calling for non-zero" << std::endl;
        std::fill_n(data_, N, x);
    }
};

template <typename T>
struct base_with_array<T, 0>
{
    void fill(const T& x) { 
        std::cout << "calling for zero" << std::endl;
    }
};


template <typename T, size_t N>
class cached_vector : private base_with_array<T, N> {
    public:
        cached_vector() {
            this->fill(T());
        }
};

int main() {
    cached_vector<int, 0> v1;
    cached_vector<int, 10> v2;

    return 0;
}

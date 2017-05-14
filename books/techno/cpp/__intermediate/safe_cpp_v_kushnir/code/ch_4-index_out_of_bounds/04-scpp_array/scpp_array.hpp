#ifndef __SCPP_ARRAY_HPP_INCLUDED__
#define __SCPP_ARRAY_HPP_INCLUDED__

#include "scpp_assert.hpp"

namespace scpp {

template <typename T, unsigned N>
class array {
    public:
        typedef unsigned size_type;
        array() { }

        explicit array(const T& initial_value) {
            for(size_type i = 0; i < size(); ++i)
                data_[i] = initial_value;
        }

        size_type size() const { return N; }

        T& operator[](size_type index) {
            SCPP_TEST_ASSERT(index < N,
                             "Index " << index 
                             << " must be less then " << N);
            return data_[index];
        }

        const T& operator[](size_type index) const {
            SCPP_TEST_ASSERT(index < N,
                             "Index " << index 
                             << " must be less then " << N);
            return data_[index];
        }

        T* begin() { return &data_[0]; }
        const T* begin() const { return &data_[0]; }

        T* end() { return &data_[N]; }
        const T* end() const { return &data_[N]; }

    private:
        T data_[N];
};

} // scpp

#include <ostream>
template <typename T, unsigned N>
inline
std::ostream& operator<<(std::ostream& os, const scpp::array<T,N>& a)
{
    for (unsigned i = 0; i < a.size(); ++i) {
        os << a[i];
        if (i + 1 < a.size())
            os << " ";
    }
    return os;
}

#endif // __SCPP_ARRAY_HPP_INCLUDED__

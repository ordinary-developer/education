#ifndef __SCPP_VECTOR_HPP_INCLUDED__
#define __SCPP_VECTOR_HPP_INCLUDED__

#include <vector>
#include <sstream>
#include "scpp_assert.hpp"

namespace scpp {

template <typename T>
class vector : public std::vector<T> {
    public:
        typedef unsigned size_type;    

        explicit vector(size_type n = 0)
            : std::vector<T>(n) { }

        vector(size_type n, const T& value) 
            : std::vector<T>(n, value) { }

        template <class InputIterator> vector(InputIterator first,
                                              InputIterator last)
            : std::vector<T>(first, last) { }

        T& operator[] (size_type index) {
            std::stringstream stringStream;
            SCPP_TEST_ASSERT(index < std::vector<T>::size(),
                             stringStream << "Index " << index 
                             << " must be less than "
                             << std::vector<T>::size());
            return std::vector<T>::operator[](index);
        }

        const T& operator[] (size_type index) const {
            std::stringstream stringStream;
            SCPP_TEST_ASSERT(index < std::vector<T>::size(),
                             stringStream << "Index " << index
                             << " must be less than "
                             << std::vector<T>::size());
            return std::vector<T>::operator[](index);
        }
};

#include <ostream>
template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const scpp::vector<T>& v) {
    for (unsigned i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size())
            os << " ";
    }
    return os;
}

} // namespace scpp

#endif // __SCPP_VECTOR_HPP_INCLUDED__

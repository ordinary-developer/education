#include <type_traits>

// if you have no C++14

template <class T>
using remove_const_t = typename std::remove_const<T>::type;

template <class T>
using remove_reference_t = typename std::remove_reference<T>::type;

template <class T>
using add_lvalue_reference_t =
    typename std::add_lvalue_reference<T>::type;

int main() {
}


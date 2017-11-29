#pragma once

#include "definitions.hpp"

MXT_NAMESPACE_BEGIN(framework1)

template <typename T>
inline bool is_empty(const T& x) {
    return x.empty();
}

template <>
inline bool is_empty(const char* const& x) {
    return 0 == x || 0 == *x;
}

MXT_NAMESPACE_END(framework1)

 

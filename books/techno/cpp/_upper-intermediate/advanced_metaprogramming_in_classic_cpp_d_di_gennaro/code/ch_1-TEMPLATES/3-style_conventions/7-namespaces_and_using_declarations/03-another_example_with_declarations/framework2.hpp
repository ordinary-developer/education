#pragma once

#include "framework2.hpp"

MXT_NAMESPACE_BEGIN(framework2)

using framework1::is_empty;    

template <typename string_t>
void do_something(const string_t& x) {
    if (is_empty(x)) { }
}

MXT_NAMESPACE_END(framework2)

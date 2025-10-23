#pragma once

#include <cstddef>
#include <string>
namespace my_hash {

template <typename T>
class hash {
    public:
        size_t operator()(T const& key) const;
};

template <>
class hash<std::string> {
    public:
        size_t operator() (std::string const& key) const;
};

}

#include "hash_map.inl"

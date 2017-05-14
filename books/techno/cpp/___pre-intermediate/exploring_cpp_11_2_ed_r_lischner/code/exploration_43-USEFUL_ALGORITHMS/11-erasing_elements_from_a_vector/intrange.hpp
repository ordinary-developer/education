#ifndef INTRANGE_HPP_
#define INTRANGE_HPP_

#include <algorithm>

class intrange {
    public:
        inline intrange(int low, int high);
        inline bool operator()(int test) const;

    private:
        int const low_;
        int const high_;
};

inline intrange::intrange(int low, int high)
    : low_{ std::min(low, high) }, high_{ std::max(low, high) }  { }

inline bool intrange::operator()(int test) const {
    return test >= low_ and test <= high_;
}

#endif


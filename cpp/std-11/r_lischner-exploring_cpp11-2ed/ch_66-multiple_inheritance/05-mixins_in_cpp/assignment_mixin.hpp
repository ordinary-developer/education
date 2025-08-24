#pragma once

template <class T>
class assignment_mixin {
    public:
        T& operator=(T rhs) {
            rhs.swap(static_cast<T&>(*this));
            return static_cast<T&>(*this);
        }

    protected:
        assignment_mixin() = default;
};

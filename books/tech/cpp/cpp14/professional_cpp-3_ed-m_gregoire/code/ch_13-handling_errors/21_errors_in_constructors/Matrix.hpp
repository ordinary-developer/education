#ifndef MATRIX_HPP
#define MATRIX_HPP


#include <cstddef>
#include "Element.hpp"

class Matrix {
    public:
        Matrix(size_t width, size_t height);
        virtual ~Matrix();
    private:
        size_t mWidth;
        size_t mHeight;
        Element** mMatrix;
};

#endif

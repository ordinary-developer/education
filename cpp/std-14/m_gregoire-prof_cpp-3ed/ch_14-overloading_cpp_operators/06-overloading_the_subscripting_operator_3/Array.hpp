#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>


template <typename T>
class Array {
    public:
        Array();
        virtual ~Array();

        Array<T>& operator = (const Array<T>& rhs) = delete;
        Array(const Array<T>& src) = delete;

        T getElementAt(size_t x) const;
        void setElementAt(size_t x, const T& val);

        T& operator [] (size_t x);
        const T& operator [] (size_t x) const;
    private:
        void initializeElements();
        void resize(size_t newSize);

        static const size_t kAllocSize = 4;
        T* mElems;
        size_t mSize;
};

template <typename T> void Array<T>::initializeElements() {
    for (size_t i = 0; i < mSize; i++) {
        mElems[i] = T();
    }
}

template <typename T> void Array<T>::resize(size_t newSize) {
    T* oldElems = mElems;
    size_t oldSize = mSize;

    mSize = newSize;
    mElems = new T[newSize];
    initializeElements();

    for (size_t i = 0; i < oldSize; i++) {
        mElems[i] = oldElems[i];
    }

    delete [] oldElems;
}

template <typename T> Array<T>::Array() {
    mSize = kAllocSize;
    mElems = new T[mSize];
    initializeElements();
}

template <typename T> Array<T>::~Array() {
    delete [] mElems;
    mElems = nullptr;
}

template <typename T> T Array<T>::getElementAt(size_t x) const {
    if (x >= mSize) {
        throw std::out_of_range("");
    }
    return mElems[x];
}

template <typename T> void Array<T>::setElementAt(size_t x, const T& val) {
    if (x >= mSize) {
        resize(x + kAllocSize);
    }
    mElems[x] = val;
}

// overloading the subscripting operator
template <typename T> T& Array<T>::operator [] (size_t x) {
    if (x >= mSize) {
        resize(x + kAllocSize);
    }
    return mElems[x];
}

template <typename T> const T& Array<T>::operator [] (size_t x) const {
    if (x >= mSize) {
        throw std::out_of_range("");
    }
    return mElems[x];
}

#endif


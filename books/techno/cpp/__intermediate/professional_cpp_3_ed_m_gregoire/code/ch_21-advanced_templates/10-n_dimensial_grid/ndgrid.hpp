#pragma once

#include <cstddef>
#include <vector>

template <typename T, size_t N>
class NDGrid {
    public:
        explicit NDGrid(size_t size = kDefaultSize);
        virtual ~NDGrid() = default;

        NDGrid<T, N - 1>& operator[](size_t x);
        NDGrid<T, N - 1> const& operator[](size_t x) const;

        void resize(size_t newSize);
        size_t getSize() const { return elements_.size(); }

        static size_t const kDefaultSize = 10;

    private:
        std::vector<NDGrid<T, N - 1>> elements_;
};

template <typename T, size_t N>
NDGrid<T, N>::NDGrid(size_t size) { resize(size); }

template <typename T, size_t N>
void NDGrid<T, N>::resize(size_t newSize) {
    elements_.resize(newSize);
    for (auto& element : elements_)
        element.resize(newSize);
}

template <typename T, size_t N>
NDGrid<T, N - 1>& NDGrid<T, N>::operator[](size_t x) { 
    return elements_[x];
}

template <typename T, size_t N>
NDGrid<T, N - 1> const& NDGrid<T, N>::operator[](size_t x) const { 
    return elements_[x]; 
}

template <typename T>
class NDGrid<T, 1> {
    public:
        explicit NDGrid(size_t size = kDefaultSize);
        virtual ~NDGrid() = default;

        T& operator[](size_t x);
        T const& operator[](size_t x) const;

        size_t getSize() const { return elements_.size(); }
        void resize(size_t newSize);

        static size_t const kDefaultSize = 10;

    private:
        std::vector<T> elements_;
};

template <typename T>
NDGrid<T, 1>::NDGrid(size_t size) { resize(size); }

template <typename T>
void NDGrid<T, 1>::resize(size_t newSize) { elements_.resize(newSize); }

template <typename T>
T& NDGrid<T, 1>::operator[](size_t x) { return elements_[x]; }

template <typename T>
T const&  NDGrid<T, 1>::operator[](size_t x) const { return elements_[x]; }

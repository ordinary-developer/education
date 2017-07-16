#pragma once

#include <cstddef>
#include <vector>

template <typename T>
class OneDGrid {
    public:
        explicit OneDGrid(size_t inSize = kDefaultSize);
        virtual ~OneDGrid() = default;

        T& operator[](size_t x);
        T const& operator[] (size_t x) const;

        void resize(size_t newSize);
        size_t getSize() const { return elements_.size(); }

        static const size_t kDefaultSize = 10;

    private:
        std::vector<T> elements_;
};

template <typename T>
OneDGrid<T>::OneDGrid(size_t inSize) { elements_.resize(inSize); }

template <typename T>
T& OneDGrid<T>::operator[](size_t x) { return elements_[x]; }

template <typename T>
T const& OneDGrid<T>::operator[](size_t x) const { return elements_[x]; }

template <typename T>
void OneDGrid<T>::resize(size_t newSize) {
    elements_.resize(newSize);
}

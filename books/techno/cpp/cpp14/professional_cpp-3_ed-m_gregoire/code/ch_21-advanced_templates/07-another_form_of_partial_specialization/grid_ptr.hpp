#pragma once

#include "grid.hpp"
#include <memory>

template <typename T>
class Grid<T*> {
    public:
        explicit Grid(size_t width = kDefaultWidth,
                      size_t height = kDefaultHeight);
        Grid(Grid<T*> const& src);

        virtual ~Grid() = default;

        Grid<T*>& operator=(Grid<T*> const& rhs); 

        void setElementAt(size_t x, size_t y, std::unique_ptr<T> element);
        T* getElementAt(size_t x, size_t y);
        const T* getElementAt(size_t x, size_t y) const;

        size_t getWidth() const { return width_; }
        size_t getHeight() const { return height_; }

        static const size_t kDefaultWidth = 10;
        static const size_t kDefaultHeight = 10;

    private:
        void initializeCellsContainer();
        void copyFrom(Grid<T*> const& src);

        std::vector<std::vector<std::unique_ptr<T>>> cells_;
        size_t width_, height_;
};

template <typename T>
Grid<T*>::Grid(size_t width, size_t height) 
    : width_{ width }, height_{ height } 
{
    initializeCellsContainer();
}

template <typename T>
void Grid<T*>::initializeCellsContainer() {
    cells_.clear();

    cells_.resize(width_);
    for (auto& column : cells_)
        column.resize(height_);
}

template <typename T>
Grid<T*>::Grid(Grid<T*> const& src) { copyFrom(src); }

template <typename T>
Grid<T*>& Grid<T*>::operator=(Grid<T*> const& rhs) {
    if (&rhs == this)
        return *this;

    copyFrom(rhs);
    return *this;
}

template <typename T>
void Grid<T*>::copyFrom(Grid<T*> const& src) {
    width_ = src.width_;
    height_ = src.height_;

    initializeCellsContainer();

    for (size_t i{0}; i < width_; ++i)
        for (size_t j{0}; j < height_; ++j)
            if (src.cells_[i][j])
                cells_[i][j].reset(new T(*(src.cells_[i][j])));
}

template <typename T>
void Grid<T*>::setElementAt(size_t x, size_t y, std::unique_ptr<T> element)
{
    cells_[x][y] = std::move(element);
}

template <typename T>
T* Grid<T*>::getElementAt(size_t x, size_t y) {
    return cells_[x][y].get();
}

template <typename T>
const T* Grid<T*>::getElementAt(size_t x, size_t y) const{
    return cells_[x][y].get();
}

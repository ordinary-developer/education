#ifndef GRID_STRING_HPP
#define GRID_STRING_HPP

#include "Grid.hpp"
#include <string>

template <>
class Grid<const char*>
{
    public:
        explicit Grid(size_t inWidth = kDefaultWidth,
            size_t inHeight = kDefaultHeight);
        virtual ~Grid();

        void setElementAt(size_t x, size_t y, const char* inElem);
        const char* getElementAt(size_t x, size_t y) const;

        size_t getHeight() const { return mHeight; }
        size_t getWidth() const { return mWidth; }

        static const size_t kDefaultWidth = 10;
        static const size_t kDefaultHeight = 10;

    private:
        void initializeCellsContainer();
        std::vector<std::vector<std::string>> mCells;
        size_t mWidth, mHeight;
};

Grid<const char*>::Grid(size_t inWidth, size_t inHeight)
    :mWidth(inWidth), mHeight(inHeight)
{
    initializeCellsContainer();
}

Grid<const char*>::~Grid() {
    // nothing to do, the vector will clean up itself
}

void Grid<const char*>::setElementAt(size_t x, size_t y, const char* inElem) {
    mCells[x][y] = (inElem) ? inElem : "";
}

const char* Grid<const char*>::getElementAt(size_t x, size_t y) const {
    return mCells[x][y].c_str();
}

void Grid<const char*>::initializeCellsContainer() {
    mCells.resize(mWidth);
    for (auto& column : mCells) {
        column.resize(mHeight);
    }
}

#endif

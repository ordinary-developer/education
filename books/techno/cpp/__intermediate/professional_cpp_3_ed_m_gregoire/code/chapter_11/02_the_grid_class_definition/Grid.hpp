#ifndef GRID_HPP
#define GRID_HPP

#include <cstdlib> // for size_t
#include <vector>

template <typename T>


class Grid {
    public:
        explicit Grid(size_t inWidth = kDefaultWidth,
                size_t inHeight = kDefaultHeight);
        virtual ~Grid();

        void setElementAt(size_t x, size_t y, const T& inElem);
        T& getElementAt(size_t x, size_t y);
        const T& getElementAt(size_t x, size_t y) const;

        size_t getHeight() const { return mHeight; }
        size_t getWidth() const { return mWidth; }

        static const size_t kDefaultWidth = 10;
        static const size_t kDefaultHeight = 10;
    private:
        void initializeCellsContainer();
        std::vector<std::vector<T>> mCells;
        size_t mWidth, mHeight;
};

template <typename T>
Grid<T>::Grid(size_t inWidth, size_t inHeight):
    mWidth(inWidth), mHeight(inHeight) 
{
    initializeCellsContainer();
}

template <typename T>
Grid<T>::~Grid() { 
    // nothing to do yet
}

template <typename T>
void Grid<T>::initializeCellsContainer() {
    mCells.resize(mWidth);
    for (std::vector<T>& column : mCells) {
        column.resize(mHeight);
    }
}

template <typename T>
void Grid<T>::setElementAt(size_t x, size_t y, const T& inElem) {
    mCells[x][y] = inElem;
}

template <typename T>
T& Grid<T>::getElementAt(size_t x, size_t y) {
    return mCells[x][y];
}

template <typename T>
const T& Grid<T>::getElementAt(size_t x, size_t y) const {
    return mCells[x][y];
}
#endif

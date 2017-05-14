#include <cstddef>


template <typename T = int, size_t WIDTH = 10, size_t HEIGHT = 10>
class Grid {
    public:
        Grid();
        virtual ~Grid();

        void setElementAt(size_t x, size_t y, const T& inElem);
        T& getElementAt(size_t x, size_t y);
        const T& getElementAt(size_t x, size_t y) const;

    private:
        T mCells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::Grid() : mCells() { }

template <typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::~Grid() 
{
    // nothing here
}

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::setElementAt(size_t x, size_t y, const T& inElem) 
{
    mCells[x][y] = inElem;
}

template <typename T, size_t WIDTH, size_t HEIGHT>
T& Grid<T, WIDTH, HEIGHT>::getElementAt(size_t x, size_t y) {
    return mCells[x][y];
}

template <typename

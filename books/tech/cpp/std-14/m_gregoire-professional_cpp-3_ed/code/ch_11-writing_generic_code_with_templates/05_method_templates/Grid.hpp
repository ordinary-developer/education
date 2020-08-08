#include <cstddef>
#include <vector>


template <typename T>
class Grid {
    public:
        explicit Grid(size_t inWidth = kDefaultWidth,
            size_t inHeight = kDefaultHeight);
        virtual ~Grid();

        template <typename E>
        Grid(const Grid<E>& src);

        template <typename E>
        Grid<T>& operator=(const Grid<E>& rhs);

        void setElementAt(size_t x, size_t y, const T& inElem);
        T& getElementAt(size_t x, size_t y);
        const T& getElementAt(size_t x, size_t y) const;


        size_t getHeight() const { return mHeight; }
        size_t getWidth() const { return mWidth; }

        static const size_t kDefaultWidth = 10;
        static const size_t kDefaultHeight = 10;
    private:
        template <typename E>
        void copyFrom(const Grid<E>& src);

        void initializeCellsContainer();
        std::vector<std::vector<T>> mCells;
        size_t mWidth, mHeight;
};

template <typename T>
Grid<T>::Grid(size_t inWidth, size_t inHeight) 
    : mWidth(inWidth), mHeight(inHeight) 
{
    initializeCellsContainer();
}

template <typename T>
void Grid<T>::initializeCellsContainer() {
    mCells.resize(mWidth);
    for (std::vector<T>& column : mCells) {
        column.resize(mHeight);
    }
}

template <typename T>
Grid<T>::~Grid() {
    // nothing to do 
}

template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E>& src) {
    copyFrom(src);
}

template <typename T>
template <typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs) {
    copyFrom(rhs);
    return *this;
}

template <typename T>
void Grid<T>::setElementAt(size_t x , size_t y, const T& inElem) {
    mCells[x][y] = inElem;
}

template<typename T>
T& Grid<T>::getElementAt(size_t x, size_t y) {
    return mCells[x][y];
}

template<typename T>
const T& Grid<T>::getElementAt(size_t x, size_t y) const {
    return mCells[x][y];
}

template<typename T>
template <typename E>
void Grid<T>::copyFrom(const Grid<E>& src) {
    mWidth = src.getWidth();
    mHeight = src.getHeight();

    initializeCellsContainer();

    for (size_t i = 0; i < mWidth; i++) {
        for (size_t j = 0; j < mHeight; j++) {
            mCells[i][j] = src.getElementAt(i, j);
        }
    }

}

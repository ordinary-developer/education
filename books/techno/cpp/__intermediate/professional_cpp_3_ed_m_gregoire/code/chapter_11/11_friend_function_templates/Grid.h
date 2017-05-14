#ifndef GRID_HPP
#define GRID_HPP

#include <cstddef>
#include <vector>
#include <algorithm>

// Forward declare Grid template.
template <typename T> class Grid;

// Prototype for templatized operator+.
template<typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs);

template <typename T>
class Grid
{
public:
	explicit Grid(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	virtual ~Grid();

	// Sets an element at a given location. The element is copied.
	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

	friend Grid<T> operator+ <T>(const Grid<T>& lhs, const Grid<T>& rhs);

private:
	void initializeCellsContainer();
	std::vector<std::vector<T>> mCells;
	size_t mWidth, mHeight;
};

template <typename T>
Grid<T>::Grid(size_t inWidth, size_t inHeight)
: mWidth(inWidth)
, mHeight(inHeight)
{
	initializeCellsContainer();
}

template <typename T>
Grid<T>::~Grid()
{
	// Nothing to do, the vector will clean up itself.
}

template <typename T>
void Grid<T>::initializeCellsContainer()
{
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
	}
}

template <typename T>
void Grid<T>::setElementAt(size_t x, size_t y, const T& inElem)
{
	mCells[x][y] = inElem;
}

template <typename T>
T& Grid<T>::getElementAt(size_t x, size_t y)
{
	return mCells[x][y];
}

template <typename T>
const T& Grid<T>::getElementAt(size_t x, size_t y) const
{
	return mCells[x][y];
}

template <typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs)
{
	size_t minWidth = std::min(lhs.getWidth(), rhs.getWidth());
	size_t minHeight = std::min(lhs.getHeight(), rhs.getHeight());

	Grid<T> result(minWidth, minHeight);
	for (size_t y = 0; y < minHeight; ++y) {
		for (size_t x = 0; x < minWidth; ++x) {
			result.setElementAt(x, y, lhs.mCells[x][y] + rhs.mCells[x][y]);
		}
	}

	return result;
}
#endif

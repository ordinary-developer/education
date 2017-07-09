#pragma once

#include <cstddef>
#include <vector>

template <typename T, const T& DEFAULT>
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

private:
	void initializeCellsContainer();
	std::vector<std::vector<T>> mCells;
	size_t mWidth, mHeight;
};

template <typename T, const T& DEFAULT>
Grid<T, DEFAULT>::Grid(size_t inWidth, size_t inHeight)
: mWidth(inWidth)
, mHeight(inHeight)
{
	initializeCellsContainer();
}

template <typename T, const T& DEFAULT>
Grid<T, DEFAULT>::~Grid()
{
	// Nothing to do, the vector will clean up itself.
}

template <typename T, const T& DEFAULT>
void Grid<T, DEFAULT>::initializeCellsContainer()
{
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
		for (auto& element : column) {
			element = DEFAULT;
		}
	}
}

template <typename T, const T& DEFAULT>
void Grid<T, DEFAULT>::setElementAt(size_t x, size_t y, const T& inElem)
{
	mCells[x][y] = inElem;
}

template <typename T, const T& DEFAULT>
T& Grid<T, DEFAULT>::getElementAt(size_t x, size_t y)
{
	return mCells[x][y];
}

template <typename T, const T& DEFAULT>
const T& Grid<T, DEFAULT>::getElementAt(size_t x, size_t y) const
{
	return mCells[x][y];
}

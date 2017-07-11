#pragma once

#include <cstddef>

template <typename T, size_t WIDTH, size_t HEIGHT>
class Grid {
    public:
        Grid();
        virtual ~Grid() = default;

        void setElementAt(size_t x, size_t y, T const& element);
        T& getElementAt(size_t x, size_t y);
        T const& getElementAt(size_t x, size_t y) const;

        size_t getHeight() const { return HEIGHT; }
        size_t getWidth() const { return WIDTH; }

    private:
        T cells_[WIDTH][HEIGHT];
};

// partial specialization
#include <string>
template <size_t WIDTH, size_t HEIGHT>
class Grid<const char*, WIDTH, HEIGHT> {
    public:
        Grid();
        virtual ~Grid() = default;

        void setElementAt(size_t x, size_t, const char* element);
        const char* getElementAt(size_t x, size_t y) const;

        size_t getWidth() const { return WIDTH; }
        size_t getHeight() const { return HEIGHT; }

    private:
        std::string cells_[WIDTH][HEIGHT];            
};

template <typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::Grid()
    : cells_{} { }

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::setElementAt(size_t x, 
                                          size_t y, 
                                          T const& element)
{
    cells_[x][y] = element;
}

template <typename T, size_t WIDTH, size_t HEIGHT>
T& Grid<T, WIDTH, HEIGHT>::getElementAt(size_t x, size_t y) {
    return cells_[x][y];
}

template <typename T, size_t WIDTH, size_t HEIGHT>
T const& Grid<T, WIDTH, HEIGHT>::getElementAt(size_t x, size_t y) const
{
    return cells_[x][y];
}

// PARTIAL SPECIALIZATION
template <size_t WIDTH, size_t HEIGHT>
Grid<const char*, WIDTH, HEIGHT>::Grid() : cells_{} { }

template <size_t WIDTH, size_t HEIGHT>
void Grid<const char*, WIDTH, HEIGHT>::setElementAt(
    size_t x, size_t y, const char* element)
{
    cells_[x][y] = element ? element : "";
}

template <size_t WIDTH, size_t HEIGHT>
const char* Grid<const char*, WIDTH, HEIGHT>::getElementAt(
    size_t x, size_t y) const
{
    return cells_[x][y].c_str(); 
}


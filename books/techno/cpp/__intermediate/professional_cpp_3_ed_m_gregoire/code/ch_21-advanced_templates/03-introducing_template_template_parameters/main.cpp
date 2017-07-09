#include <cstddef>
#include <vector>
template <typename T,
          template <typename E, typename Allocator = std::allocator<E>>
            class Container = std::vector>
class Grid {
    public:
        explicit Grid(size_t width = kDefaultWidth,
                      size_t height = kDefaultHeight)
        : width_{ width }, height_ { height }
        {
            initializeCellsContainer();
        }
        virtual ~Grid() = default;

        void setElementAt(size_t x, size_t y, T const& element) {
            cells_[x][y] = element;
        }

        T& getElementAt(size_t x, size_t y) { return cells_[x][y]; }

        T const& getElementAt(size_t x, size_t y) const {
            return cells_[x][y];
        }

        size_t getWidth() const { return width_; }
        size_t getHeight() const { return height_; }

        static const size_t kDefaultWidth = 10;
        static const size_t kDefaultHeight = 10;

    private:
        void initializeCellsContainer() {
            cells_.resize(width_);
            for (auto& column : cells_)
                column.resize(height_);
        }

        std::vector<Container<T>> cells_;
        size_t width_, height_;
};

#include <iostream>
#include <vector>
#include <deque>
int main() {
    Grid<int, std::vector> myGrid{};
    myGrid.setElementAt(1, 2, 3);
    std::cout << myGrid.getElementAt(1, 2) << std::endl;
    Grid<int, std::vector> myGrid2{myGrid};

    return 0;
}

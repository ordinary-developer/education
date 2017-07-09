#include <cstddef>
#include <vector>

template <typename T, const T DEFAULT = T()>
class Grid {
    public:
        explicit Grid(size_t width = kDefaultWidth,
                      size_t height = kDefaultHeight)
            : width_{ width }, height_{ height }
        {
            initializeCellsContainers();
        }
        virtual ~Grid() = default;

        void setElementAt(size_t x, size_t y, T const& element) {
            cells_[x][y] = element;
        }

        T& getElementAt(size_t x, size_t y) {
            return cells_[x][y];
        }

        T const& getElementAt(size_t x, size_t y) const {
            return cells_[x][y];
        }

        size_t getWidth() const { return width_; }
        size_t getHeight() const { return height_; }

        static const size_t kDefaultWidth = 10;
        static const size_t kDefaultHeight = 10;

    private:
        void initializeCellsContainers() {
            cells_.resize(width_);
            for (auto& column : cells_) {
                column.resize(height_);
                for (auto& element : column)
                    element = DEFAULT;
            }
        }


        std::vector<std::vector<T>> cells_;
        size_t width_, height_;
};


int main() {
    Grid<int> myIntGrid{};
    Grid<int, 10> myIntGrid2{};

    return 0;
}

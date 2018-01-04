#include <iostream>
#include <memory>
#include <vector>
namespace example01 {

template <typename T, int SIZE> 
class fsize_vector {
    public:
        using self = fsize_vector;

        fsize_vector()
            : data_{ new T[MY_SIZE] }
        {}

        int size() const { return MY_SIZE; }

        T& operator[](int const i) { return data_[i]; }    
        T const& operator[](int const i) const { return data_[i]; }

        template <typename Vector>
        self& operator=(Vector const& that) {
            for (int i{0}; i < MY_SIZE; ++i)
                data_[i] = that[i];
            return *this;
        }
        
        static int const MY_SIZE = SIZE;

    private:
        std::unique_ptr<T[]> data_;
};

template <typename T, int N>
std::ostream& operator<<(std::ostream& stream, fsize_vector<T, N> const& v) {
    stream << '[';
    for (int i{0}; i < v.size(); ++i)
        stream << v[i] << ',';
    stream << ']';
    return stream;
}

void run() {
    fsize_vector<int, 5> v{};
    std::vector<int> std_v{1, 2, 3, 4, 5};
    v = std_v;
    std::cout << v << std::endl;
}

} // namespace example01

int main() {
    example01::run();

    return 0;
}

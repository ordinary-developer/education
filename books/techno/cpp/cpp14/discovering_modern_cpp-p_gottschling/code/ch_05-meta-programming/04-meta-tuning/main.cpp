// generic vector assignment
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


// functor for assignment
#include <iostream>
#include <memory>
#include <vector>
namespace example02 {

template <typename Target, typename Source, int N>
struct fsize_assign {
    void operator()(Target& tar, Source const& src) {
        fsize_assign<Target, Source, N - 1>()(tar, src);
        std::cout << "assign entry " << N << '\n';
        tar[N] = src[N];
    }
};

template <typename Target, typename Source>
struct fsize_assign<Target, Source, 0> {
    void operator()(Target& tar, Source const& src) {
        std::cout << "assign entry " << 0 << '\n';
        tar[0] = src[0];
    }
};

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

        self& operator=(self const& that) {
            fsize_assign<self, self, MY_SIZE - 1>{}(*this, that);
            return *this;
        }

        template <typename Vector>
        self& operator=(Vector const& that) {
            fsize_assign<self, Vector, MY_SIZE - 1>{}(*this, that);
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
} // namespace example02

// assignment functor with parametrized operator 
#include <iostream>
#include <memory>
#include <vector>
namespace example03 {

template <int N>
struct fsize_assign {
    template <typename Target, typename Source>
    void operator()(Target& tar, Source const& src) {
        fsize_assign<N - 1>()(tar, src);
        std::cout << "assign entry " << N << '\n';
        tar[N] = src[N];
    }
};

template <>
struct fsize_assign<0> {
    template <typename Target, typename Source>
    void operator()(Target& tar, Source const& src) {
        std::cout << "assign entry " << 0 << '\n';
        tar[0] = src[0];
    }
};

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

        self& operator=(self const& that) {
            fsize_assign<MY_SIZE - 1>{}(*this, that);
            return *this;
        }

        template <typename Vector>
        self& operator=(Vector const& that) {
            fsize_assign<MY_SIZE - 1>{}(*this, that);
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
} // namespace example03

// unrolling nested  loops
#include <cassert>
#include <iostream>
#include <vector>
namespace example04 {

template <typename Target, typename Source, int N>
struct fsize_assign {
    void operator()(Target& tar, const Source& src) {
        fsize_assign<Target, Source, N-1>()(tar, src);
        std::cout << "tar[" << N << "] = src[" << N << "]\n";
        tar[N] = src[N];
    }
};

template <typename Target, typename Source>
struct fsize_assign<Target, Source, 0> {
    void operator()(Target& tar, Source const& src) {
        std::cout << "tar[0] = src[0]\n";
        tar[0] = src[0];
    }
};


template <typename T, int Rows, int Cols>
class fsize_matrix {
    static_assert(Rows > 0, "Rows must be larger than 0.");
    static_assert(Cols > 0, "Cols must be larger than 0.");

    using self = fsize_matrix;

    public:
        using value_type = T;
        static int const MY_ROWS{ Rows };
        static int const MY_COLS{ Cols };

        fsize_matrix() {}

        fsize_matrix(self const& that) {
            for (int i{0}; i < MY_ROWS; ++i)
                for (int j{0}; j < MY_COLS; ++i)
                    data_[i][j] = that.data_[i][j];
        }


        const T* operator[](int r) const { return data_[r]; }
        T* operator[](int r) { return data_[r]; }

    private:
        T data_[Rows][Cols];
};

template <typename T, int Rows, int Cols>
class fsize_matrix {
    private:
        T data_[Rows][Cols];
};

void run() {
    std::vector<int> v1{ 1, 2, 3}, v2{1, 2, 3};
    fsize_assign<std::vector<int>, std::vector<int>, 3> fsize_assign_functor{};
    fsize_matrix<int, 3, 3> matrix{};
}
} // namespace example04

int main() {
    example01::run();
    std::cout << "\n[OK] - example01" << '\n' << "--------------" << std::endl;

    example02::run();
    std::cout << "\n[OK] - example02" << '\n' << "--------------" << std::endl;

    example03::run();
    std::cout << "\n[OK] - example03" << '\n' << "--------------" << std::endl;

    example04::run();
    std::cout << "\n[OK] - example04" << '\n' << "--------------" << std::endl;

    return 0;
}

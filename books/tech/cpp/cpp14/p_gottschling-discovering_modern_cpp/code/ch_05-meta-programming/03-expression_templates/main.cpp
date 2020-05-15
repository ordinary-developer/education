// simple operator implementation
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
namespace example01 {

template <typename T>
class my_vector {
    public:
        explicit my_vector(size_t size) 
            : size_{ size }, data_{ new T[size] } 
        { } 

        explicit my_vector(std::initializer_list<T> const& data) {
            size_ = data.size();
            data_ = new T[size_];

            size_t i{0};
            for (auto const& element : data)
                data_[i++] = element;
        }

        my_vector(my_vector const& that) 
            : size_{ that.size_ }, data_{ new T[that.size_] }
        {
            std::copy(&that.data_[0], &that.data_[that.size_], &data_[0]);
        }

        my_vector& operator=(my_vector const& that) {
            std::copy(&that.data_[0], &that.data_[that.size_], &data_[0]);
            return *this;
        }

        ~my_vector() {
            if (nullptr != data_) 
                delete[] data_;
        }

        T const& operator[](size_t i) const { return data_[i]; }
        T& operator[](size_t i) { return data_[i]; }

        size_t size() const { return size_; }

    private:
        size_t size_;
        T* data_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, my_vector<T> const& v) {
    os << '[';
    for (size_t i{0}; i < v.size(); ++i)
        os << v[i] << ',';
    os << ']';
    return os;
}

template <typename T>
inline my_vector<T> operator+(my_vector<T> const& x, my_vector<T> const& y) {
    my_vector<T> sum( x.size() );
    for (size_t i{0}; i != x.size(); ++i)
        sum[i] = x[i] + y[i];
    return sum;
}

void run() {
    my_vector<float> x{ 1.0, 1.0, 2.0, -3.0 },
                     y{1.7, 1.7, 4.0, -6.0},
                     z{4.1, 4.1, 2.6, 11.0},
                     w(4);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "w = " << w << std::endl;

    w = x + y + z;
    std::cout << "w = " << w << std::endl;
}
} // namespace example01

#include <cassert>
#include <memory>
#include <memory>
#include <cstdlib>
namespace example02 {

template <typename T>
class my_vector {
    public:
        void check_size(size_t const that_size) const { 
            assert(that_size == size_);
        }
        void check_index(size_t const i) const { 
            assert(i >= 0 and i < size_);
        }

        explicit my_vector(size_t const size) 
            : size_{ size }, data_{ new T[size] } {};

        my_vector(my_vector const& that) 
            : size_{ that.size_ }, data_{ new T[that.size_] }
        {
            for (size_t i{0}; i < size_; ++i)
                data_[i] = that.data_[i];
        }

        my_vector& operator=(my_vector const& that) {
            check_size(that.size());
            for (size_t i{0}; i < size_; ++i)
                data_[i] = that.data_[i];
            return *this;
        }

        my_vector& operator=(vector_sum<T> const& that) {
            check_size(that.size());
            for (size_t i{0}; i < size_; ++i)
                data_[i] = that[i];
            return *this;
        }

        size_t size() const { return size_; }

        T const& operator[](size_t i) const {
            check_index(i);
            return data_[i];
        }

        T& operator[](size_t i) {
            check_index(i);
            return data_[i];
        }

    private:
        size_t size_;
        std::unique_ptr<T[]> data_;
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, my_vector<T> const& v) {
    os << '[';
    for (size_t i{0}; i < v.size(); ++i)
        os << v[i] << ',';
    os << ']';
    return os;
}

template <typename T> class vector_sum;
template <typename T> class vector_sum3;

template <typename T>
class vector_sum {
    public:
        vector_sum(my_vector<T> const& v1, my_vector<T> const& v2)
            : v1_{v1}, v2_{v2} 
        {
            assert(v1_.size() == v2_.size());
        }

        T operator[](size_t i) const {
            check_index(i);
            return v1_[i] + v2_[i];
        }

        size_t size() const { return v1_.size(); }

        template <typename U>
        friend vector_sum3<U> inline operator+(vector_sum<U> const& x,
                                               my_vector<U> const& y);

    private:
        void check_index(size_t const i) const { 
            assert(i >= 0 and i < v1_.size()); 
        }

        my_vector<T> const& v1_, v2_;
};

template <typename T>
vector_sum<T> inline operator+(my_vector<T> const& x, my_vector<T> const& y) {
    return {x, y};
}

template <typename T>
class vector_sum3 {
        void check_index(size_t const i) const {
            assert(i >= 0 and i < v1_.size());
        }

    public:
        vector_sum3(my_vector<T> const& v1,
                    my_vector<T> const& v2,
                    my_vector<T> const& v3)
        {
            assert(v1.size() == v2.size());
            assert(v1.size() == v3.size());
        }

        size_t size() const { return v1_.size(); }

        T operator[](size_t i) const { 
            check_index(i);
            return v1_[i] + v2_[i] + v3_[i];
        }

    private:
        my_vector<T> const& v1_, v2_, v3_;
};

template <typename T>
vector_sum3<T> inline operator+(vector_sum<T> const& x,
                                my_vector<T> const& y)
{
    return vector_sum3<T>(x.v1_, x.v2_, y);
}

void run() {
    my_vector<float> x(4), y(4), w(4);
    x[0] = x[1] = 1.0; x[2] = 2.0; x[3] = -3.0;
    y[0] = y[1] = 1.0; y[2] = 2.0; y[3] = -3.0;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "w = " << w << std::endl;
}
} // namespace example02

int main() {
    example01::run();
    std::cout << "[OK] example01" << std::endl;
    std::cout << "----------------" << std::endl;

    example02::run();
    std::cout << "[OK] example02" << std::endl;
    std::cout << "----------------" << std::endl;

    return 0;
}

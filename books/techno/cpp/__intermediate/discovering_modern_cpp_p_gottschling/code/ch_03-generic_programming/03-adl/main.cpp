namespace example01 {

namespace chez_herbert {
    struct matrix{};
}

namespace rocketscience {
    struct matrix{};

    void initialize(matrix& A) { }
    void initialize(chez_herbert::matrix& A) { }

    matrix operator+(matrix const& A, matrix const& B) {
        matrix C{};
        initialize(C);
        return C;
    }
}

void run() {
    rocketscience::matrix A{}, B{}, C{}, D{};
    rocketscience::initialize(B);
    initialize(C); // rely on ADL
    A = B + C + D;

    chez_herbert::matrix E{}, F{}, G{};
    rocketscience::initialize(E);
    //initialize(E); // Error: initialize not found
}
} // example01

namespace example02 {

namespace rocketscience {
    namespace mat {
        struct sparse_matrix{};
        struct dense_matrix{};
        struct uber_matrix{};

        template <typename Matrix>
        double one_norm(Matrix const& A) { return 0; }
    }

    namespace vec {
        struct sparse_vector{};
        struct dense_vector{};
        struct uber_vector{};

        template <typename Vector>
        double one_norm(Vector const& x) { return 0; }
    }
}

void run() { 
    rocketscience::mat::uber_matrix x{};
    double norm_x = one_norm(x);

    rocketscience::vec::uber_vector y{};
    double norm_y = one_norm(y);
}
} // example02

namespace example03 {

namespace rocketscience {
    namespace vec {
        struct sparse_vector{};
        struct dense_vector{};
        struct uber_vector{};
    }

    template <typename Vector>
    double one_norm(Vector const& x) { return 0; }
}

void run() {
    rocketscience::vec::uber_vector x{};
    double norm_x = rocketscience::one_norm(x);
}
} // example03

namespace example04 {

namespace rocketscience {
    namespace mat {
        template <typename Scalar, typename Matrix>
        Matrix operator*(Scalar const& a, Matrix const& A) { return A; }

        struct uber_matrix{};
    }

    namespace vec {
        template <typename Scalar, typename Vector>
        Vector operator*(Scalar const& a, Vector const& X) { return X; }

        struct uber_vector{};
    }

    template <typename Matrix, typename Vector>
    Vector operator*(Matrix const& A, Vector const& B) { return B; }
}

void run() {
    rocketscience::mat::uber_matrix a{};
    rocketscience::vec::uber_vector x{}, y{};
    // y = a * x; // here error will be
}
}

#include <iostream>
#include <utility>
#include <vector>
namespace example05 {

template <typename Value> 
class vector {
    public:
        vector() {
            size_ = 42;
            data_ = new Value[size_];
        }

        ~vector() {
            delete[] data_;
            data_ = nullptr;
        }

       friend void swap(vector& x, vector& y) {
           std::cout << "user-defined swap function" << std::endl;
           std::swap(x.size_, y.size_);
           std::swap(x.data_, y.data_);
       }

    private:
        unsigned size_;
        Value* data_;
};

template <typename T>
inline void some_function(T& x, T& y) {
    using std::swap;
    swap(x, y);
}

void run() { 
    vector<int> v1{}, v2{};
    swap(v1, v2);

    vector<int> v3{}, v4{};
    some_function(v3, v4);

    std::vector<int> v5{}, v6{};
    some_function(v5, v6);
}
    
} // example05

int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();

    return 0;
}

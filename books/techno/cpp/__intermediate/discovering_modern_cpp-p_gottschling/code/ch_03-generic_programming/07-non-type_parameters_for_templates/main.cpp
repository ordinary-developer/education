#include <cassert>
#include <algorithm>
#include <iostream>
namespace example01 {

template <typename T, int Size = 3>
class fsize_vector {
        using self = fsize_vector;
    public:
        const static int MY_SIZE = Size;

        using value_type = T;

        fsize_vector(int s = Size) { assert(s == Size); }

        self& operator= (self const& that) {
            std::copy(that.data_, that.data_ + Size, data_);
            return *this;
        }

        self operator+(self const& that) const {
            self sum{};
            for (int i{0}; i < MY_SIZE; ++i)
                sum[i] = data_[i] + that.data_[i];
            return sum;
        }

    private:
        T data_[MY_SIZE];
};

void run() {
    fsize_vector<float> v, w, x, y;
    fsize_vector<float, 4> space_time;
    fsize_vector<float, 11> string;
}

} // namespace example01
int main() {
    example01::run();

    return 0;
}

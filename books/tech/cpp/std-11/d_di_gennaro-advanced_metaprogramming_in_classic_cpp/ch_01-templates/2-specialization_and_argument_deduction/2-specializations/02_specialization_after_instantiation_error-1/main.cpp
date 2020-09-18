template <typename scalar_t>
scalar_t sq(const scalar_t& x) { }

struct A {
    A(int i = 3) {
        int j = sq(i); // the compiler will pick the generic template
    }
};

template <>
int sq(const int& x) { }

int main() {
}

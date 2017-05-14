template <typename scalar_t>
scalar_t sq(const scalar_t& x) { return x * x; }

int main() {
    double pi = 3.14;
    sq(pi);

    double x1 = sq<double>(3.14);
    double x2 = sq(3.14);
    auto x3 = sq(3.14);

    return 0;
}

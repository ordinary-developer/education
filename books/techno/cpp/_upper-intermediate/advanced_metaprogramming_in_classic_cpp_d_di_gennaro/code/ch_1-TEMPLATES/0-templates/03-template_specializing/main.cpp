template <typename scalar_t>
inline scalar_t sq(const scalar_t& x) {
    return x * x;
}

template <>
inline double sq(const double& x) {
    return x * x + 1;
}

int main() {
    return 0;
}

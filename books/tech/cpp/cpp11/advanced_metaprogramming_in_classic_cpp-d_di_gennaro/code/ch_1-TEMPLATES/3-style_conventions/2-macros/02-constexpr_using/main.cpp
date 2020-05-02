constexpr int sq(int n) { return n * n; }
constexpr int max(int a, int b) { return a < b ? b : a; }


template <int N>
struct SomeClass {
    static const int value = sq(N) / max(N, 1);
};

int main() {
    return 0;
}

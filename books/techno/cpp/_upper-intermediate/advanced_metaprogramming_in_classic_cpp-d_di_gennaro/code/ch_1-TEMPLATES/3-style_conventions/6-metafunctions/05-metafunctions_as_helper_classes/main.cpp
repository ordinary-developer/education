template <int N>
struct ttnp1_helper {
    static const int value = (1 << N);
};


template <int N>
struct two_to_plus_one {
    static const int value = ttnp1_helper<N>::value + 1;
};


template <int N>
struct two_to_plus_one2 {
    private:
        static const int aux = (1 << N);

    public:
        static const int value = aux + 1;
};

int main() {
    return 0;
}

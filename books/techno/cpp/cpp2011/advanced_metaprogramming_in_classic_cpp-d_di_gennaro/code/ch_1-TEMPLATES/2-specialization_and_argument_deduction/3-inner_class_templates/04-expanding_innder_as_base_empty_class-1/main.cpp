struct basic_inner { };

template <typename T>
struct outer {
    typedef basic_inner inner;
};

template <>
struct outer<int> {
    typedef basic_inner inner;
};

int main() {
    return 0;
}

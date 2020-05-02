template <typename T>
struct C;

template <>
struct C<void> { };

template <typename T>
struct C {
    C(C<void>) { }
};


int main() {
    return 0;
}

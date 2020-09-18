// template specializations are valid only at the namespace level
struct X {
    template <typename T>
    class Y { };

    // illegal, but usually tolerated by compilers
    template <>
    class Y<double> { };
};

// legal
template <>
class X::Y<int> { };


int main() {
    return 0;
}

template <typename int_t, int_t N>
class AnotherClass { };

// here an error will be
// template <typename T>
// class AnotherClass<T, 0> { };

// only a full specialization is allowed
template <>
class AnotherClass<int, 0> { };

int main() {
    return 0;
}

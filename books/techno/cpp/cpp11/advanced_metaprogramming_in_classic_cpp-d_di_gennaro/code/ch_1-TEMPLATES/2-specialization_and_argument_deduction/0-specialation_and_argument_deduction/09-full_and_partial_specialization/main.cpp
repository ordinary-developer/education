template <typename T>
struct is_a_pointer_type {
    static const int value = 1;
};

// full specialization for void*
template <>
struct is_a_pointer_type<void*> {
    static const int value = 2;
};

// partial specialization for all pointers
template <typename X>
struct is_a_pointer_type<X*> {
    static const int value = 3;
};

// recursive partial specialization
template <typename X>
struct is_a_pointer_type<const X> {
    static const int value = is_a_pointer_type<X>::value;
};


int main() {
    int b1 = is_a_pointer_type<int*>::value;
    int b2 = is_a_pointer_type<void*>::value;
    int b3 = is_a_pointer_type<float>::value;

    return 0;
}

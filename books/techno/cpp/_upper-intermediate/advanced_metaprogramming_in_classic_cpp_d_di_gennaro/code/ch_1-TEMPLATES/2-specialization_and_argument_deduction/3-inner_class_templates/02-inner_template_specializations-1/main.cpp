// primary template with "inner_1"
template <typename T>
class outer {
    template <typename X>
    class inner { };
};

// full specialization of outer with "inner_2"
template <>
class outer<int> {
    template <typename X>
    class inner { };
};

// "inner_2" specialization
template <>
class outer<int>::inner<float> { };

// specialization of "inner_1" for fixed T(=double) and generic X
template <>
template <typename X>
class outer<double>::inner { };

// specialization of "inner_1" for fixed T(=double) and fixed X(=char) 
template <>
template <>
class outer<double>::inner<char> { };

// illegal to specialize "inner_1" for fixed X with any T
/*
template <typename T>
template <>
class outer<T>::inner<float> { };
*/


int main() {
    return 0;
}

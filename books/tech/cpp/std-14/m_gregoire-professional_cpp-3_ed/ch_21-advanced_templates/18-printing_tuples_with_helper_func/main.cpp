#include <iostream>
#include <tuple>

template <int n, typename TupleType>
class tuple_print_helper {
    public:
        tuple_print_helper(TupleType const& t) {
            tuple_print_helper<n - 1, TupleType> tp{t};
            std::cout << std::get<n - 1>(t) << std::endl;
        }
};

template <typename TupleType>
class tuple_print_helper<0, TupleType> {
    public:
        tuple_print_helper(TupleType const&) { }
};

template <typename T>
void tuple_print(T const& t) {
    tuple_print_helper<std::tuple_size<T>::value, T> tph{t};
}

int main() {
    auto t1 = std::make_tuple(167, "Testing", false, 2.3);
    tuple_print(t1);
}

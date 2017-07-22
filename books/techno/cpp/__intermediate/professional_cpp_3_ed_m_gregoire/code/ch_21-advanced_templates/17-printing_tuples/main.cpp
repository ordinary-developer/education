#include <iostream>
#include <tuple>

template <int n, typename TupleType>
class tuple_print {
    public:
        tuple_print(TupleType const& t) {
            tuple_print<n - 1, TupleType> tp{t};
            std::cout << std::get<n - 1>(t) << std::endl;
        }
};

template <typename TupleType>
class tuple_print<0, TupleType> {
    public:
        tuple_print(TupleType const&) { }
};


#include <string>
int main() {
    using MyTuple = std::tuple<int, std::string, bool>;
    MyTuple t1{16, "Test", true};
    tuple_print<std::tuple_size<MyTuple>::value, MyTuple> tp{t1};

    return 0;
}

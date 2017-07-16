#include <string>

#include "types.hpp"

template <typename T1, typename T2, typename Result>
Result DoAddition1(T1 const& t1, T2 const& t2) { return t1 + t2; }

template <typename T1, typename T2>
auto DoAddition2(T1 const& t1, T2 const& t2) -> decltype(t1 + t2) {
    return t1 + t2;
}

template <typename T1, typename T2>
auto DoAddition3(T1 const& t1, T2 const& t2) {
    return t1 + t2;
}

int main() {
    MyInt i{ 4 };
    MyString str{ "5" };
    MyInt a{ i + str };
    MyString b{ str + i };

    auto c = DoAddition1<MyInt, MyString, MyInt>(i, str);

    auto d = DoAddition2(i, str);
    auto e = DoAddition2(str, i);

    auto f = DoAddition3(i, str);
    auto g = DoAddition3(str, i);

    return 0;
}

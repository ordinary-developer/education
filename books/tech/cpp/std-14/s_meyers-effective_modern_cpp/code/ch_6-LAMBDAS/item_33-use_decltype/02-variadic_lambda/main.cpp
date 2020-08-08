#include <iostream>

template <typename... Ts>
void normalize(Ts&&... params) {
}


int main() {
    std::string str1 = "lvalue string1";
    std::string str2 = "lvalue string2";
    normalize(str1, str2);

    normalize(std::string("rvalue string1"),
              std::string("rvalue string2"));

    auto f =
        [](auto&&... params)
        {
            return
              normalize(std::forward<decltype(params)>(params)...);
        };
    f(str1, str2);
    f(std::string("rvalue string1"), std::string("rvalue string2"));

    return 0;
}


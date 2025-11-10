#include <iostream>
#include <string>
#include <type_traits>
namespace example_01 { // -> the "getting ready", "how to do it" and "how it works" sections


using namespace std::string_literals;

struct foo {
    std::string serialize() { return "plain"s; }
};

struct bar {
    std::string serialize_with_encoding() { return "encoded"s; }
};

template <typename T>
struct is_serializable_with_encoding { static const bool value = false; };

template <>
struct is_serializable_with_encoding<bar> { static const bool value = true; };

template <bool b>
struct serializer {
    template <typename T>
    static auto serialize(T & v) { return v.serialize(); }
};

template <>
struct serializer<true> {
    template <typename T>
    static auto serialize(T & v) {
        return v.serialize_with_encoding();
    }
};

template <typename T>
auto serialize(T & v) {
    return serializer<is_serializable_with_encoding<T>::value>::serialize(v);
}

void run() {
    {
        std::cout << is_serializable_with_encoding<foo>::value << '\n';
        std::cout << is_serializable_with_encoding<bar>::value << '\n';
        std::cout << is_serializable_with_encoding<int>::value << '\n';
        std::cout << is_serializable_with_encoding<std::string>::value << '\n';
    }

    {
        foo f{};
        bar b{};

        std::cout << serialize(f) << '\n';
        std::cout << serialize(b) << '\n';
    }
}
} // example_01


#include <iostream>
int main() {
    std::cout << "[example_01] -> " << std::endl;
    example_01::run();
    std::cout << "-> ok" << std::endl << std::endl;
} 

#include <iostream>
#include <string>
#include <variant>
namespace example_01 { // -> the "how to do it..." section

void run() {
    {
        struct foo {
            int value;
            explicit foo(int const i) : value{i} {}
        };

        std::variant<int, std::string, foo> v = 42;
        v.emplace<foo>(42);
    }

    {
        std::variant<int, double, std::string> v = 42;
        auto i1 = std::get<int>(v);
        auto i2 = std::get<0>(v);

        try {
            auto f = std::get<double>(v);
        }
        catch (std::bad_variant_access const & e) {
            std::cout << e.what() << '\n';
        }
    }

    {
        std::variant<int, double, std::string> v{};
        v = 42;
        v = 42.0;
        v = "42";
    }

    {
        std::variant<int, double, std::string> v = 42;
        static_assert(std::variant_size_v<decltype(v)> == 3);
        std::cout << "index = " << v.index() << '\n';

        v = 42.0;
        std::cout << "index = " << v.index() << '\n';

        v = "42";
        std::cout << "index = " << v.index() << '\n';
    }

    {
        std::variant<int, double, std::string> v = 42;
        std::cout << "int? " << std::boolalpha << std::holds_alternative<int>(v) << '\n';

        v = "42";
        std::cout << "int? " << std::boolalpha << std::holds_alternative<int>(v) << '\n';
    }
    
    {
        struct foo {
            int value;
            explicit foo(int const i) : value{i} {}
        };

        std::variant<std::monostate, foo, int> v;

        v = 42;
        std::cout << std::get<int>(v) << '\n';

        v = foo{ 42 };
        std::cout << std::get<foo>(v).value << "\n";
    }

    {
        std::variant<int, double, std::string> v = 42;
        std::visit([](auto&& arg) { std::cout << arg << '\n'; }, v);

        v = 42.0;
        std::visit([](auto&& arg) { std::cout << arg << '\n'; }, v);

        std:visit([](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, int>)
                std::cout << "int " << arg << '\n';
            else if constexpr (std::is_same_v<T, double>)
                std::cout << "double " << arg << '\n';
            else if constexpr (std::is_same_v<T, std::string>)
                std::cout << "std::string " << arg << '\n';
        }, v);
    }
}

} // example_01


int main() {
    std::cout << "[example 01] -->" << std::endl;
    example_01::run();
    std::cout << "-> ok" << std::endl << std::endl;
    
    return 0;
}

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>
#include <cctype>
namespace example_01 { // -> the "how to do it..." section

template <typename F, typename T>
auto apply(F&& f, T value) {
    return f(value);
}

void run() {
    {
        auto i = 42;
        auto d = 42.5;
        auto s = "text";
        auto v = { 1, 2, 3 };
    }

    {
        auto b  = new char[10]{ 0 };
        auto s1 = std::string{"text"};
        auto v1 = std::vector<int>{ 1, 2, 3 };
        auto p  = std::make_shared<int>(42);
    }

    {
        auto upper = [](char const c) { return std::toupper(c); };
    }

    {
        auto add = [](auto const a, auto const b) { return a + b; };
    }

    {
        const auto func = [](const int value) { return value + 1; };
        apply(func, 10);
    }
}
} // example_01 -> the "how to do it..." section


#include <iostream>
#include <map>
#include <string>
#include <vector>
namespace example_02 { // -> the "how it works..." section

struct {
    template <typename T, typename U>
    auto operator()(T const a, U const b) const { return a + b; }
} lstruct;

void run() {
    {
        const auto v = std::vector<int>{ 1, 2, 3 };
        int size1 = v.size(); // possible loss of data
        auto size2 = v.size();
        // auto size3 = int{ v.size() }; // error
    }

    {
        std::map<int, std::string> m{};
        for (std::map<int, std::string>::const_iterator it = m.cbegin();
            it != m.cend();
            ++it)
        { /* ... */}

        for (auto it = m.cbegin(); it != m.cend(); ++it)
        { /* ... */ }    
    }

    {
        class foo {
            int x_;
        public:
            foo(int const x = 0) : x_{ x } {}
            int& get() { return x_; }
        };
        foo f{42};
        auto x = f.get();
        x = 100;
        std::cout << f.get() << '\n';

        auto& y = f.get();
        y = 100;
        std::cout << f.get() << '\n';
    }

    {
        using llong = long long;
        auto l2 = llong{42};
        auto l3 = 42LL;
    }

    {
        class foo {
            static auto func1(int const i) -> int { return 2 * i; }
            static auto func2(int const i) { return 2 * i; }
        };
    }

    {
        class foo {
            int x_;
        public:
            foo(int const x = 0) : x_{x} {}
            int& get() { return x_; }

            static auto proxy_get(foo& f) { return f.get(); }
        };

        auto f = foo{42};
        // auto& x = foo::proxy_get(f); // error
    }

    {
        class foo {
            int x_;
        public:
            foo(int const x = 0) : x_{x} {}
            int& get() { return x_; }

            static decltype(auto) proxy_get(foo& f) { return f.get(); }
        };

        auto f = foo{42};
        decltype(auto) x = foo::proxy_get(f);
    }

    {
        using namespace std::string_literals;

        auto ladd = [](auto const a, auto const b) { return a + b; };
        auto i = ladd(40, 2);
        auto s = ladd("forty"s, "two"s);
    }

    {
        using namespace std::string_literals;

        auto i = lstruct(40, 2);
        auto s = lstruct("forty"s, "two"s);
    }
}
} // example_02 -> the "how it works..." section


#include <iostream>
int main() {
    std::cout << "example_01 =>" << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 =>" << std::endl; example_02::run(); std::cout << std::endl;

    return 0;
}

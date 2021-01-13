// callable entities
namespace {
int add(int const a, int const b) { return a + b; }

struct foo {
    int x = 0;

    void increment_by(int const n) { x += n; }
};
} // anonymous namespace


#include <functional>
#include <cassert>
namespace example_01 { // base usage
void run() {
    { // -> free funcs
        auto const val = std::invoke(add, 1, 2);
        assert(3 == val);
    }

    { // -> free funcs through a pointer to a func
        auto const val1 = std::invoke(&add, 1, 2);
        assert(3 == val1);

        int(* const fadd)(int const, int const) = &add;
        auto const val2 = std::invoke(fadd, 1, 2);
        assert(3 == val2);
    }

    { // -> member funcs through a pointer to a member func
        foo constexpr f{};
        auto const val = std::invoke(&foo::x, f);
        assert(0 == val);
    }

    { // -> data members
        foo constexpr f{};
        auto const val = std::invoke(&foo::x, f);
        assert(0 == val);
    }

    { // -> func objs
        foo constexpr f{};
        auto const val = std::invoke(
            std::plus<>(), std::invoke(&foo::x, f), 3);
        assert(3 == val);
    }

    { // -> lambda expressions
        auto constexpr lambda = [](auto a, auto b) { return a + b; };
        auto const val = std::invoke(lambda, 1, 2);
        assert(3 == val);
    }
}
} // example_01


#include <functional>
#include <memory>
#include <tuple>
#include <type_traits>
#include <utility>
#include <cstddef>
namespace example_02 { // -> using invoke in meta-programming

template <class F, class T, std::size_t... I>    
auto apply_impl(F&& f, T&& t, std::index_sequence<I...>) {
    return std::invoke(
        std::forward<F>(f),
        std::get<I>(std::forward<T>(t))...);
}

template <class F, class T>
auto inhouse_apply(F&& f, T&& t) {
    return apply_impl(
        std::forward<F>(f),
        std::forward<T>(t),
        std::make_index_sequence<std::tuple_size<std::decay_t<T>>::value> {});
}

void run() {
    auto const val = inhouse_apply(add, std::make_tuple(1, 2));
    assert(3 == val);
}

} // example_02 

#include <cassert>
namespace example_03 { // ordinary call of callable objs
void run() {
    { // -> free funcs
        auto const val = add(1, 2);
        assert(3 == val);
    }

    { // -> free funcs through a pointer
        int (* const fadd1)(int const, int const) = &add;
        auto const val1 = fadd1(1, 2);
        assert(3 == val1);

        auto const fadd2 = &add;
        auto const val2 = fadd2(1, 2);
    }

    { // -> member funcs through a pointer
        foo f1{};
        f1.increment_by(3);
        auto const val1 = f1.x;
        assert(3 == val1);

        foo f2{};
        void(foo::*finc_full)(int const) = &foo::increment_by;
        (f2.*finc_full)(3);
        auto const val2 = f2.x;
        assert(3 == val2);

        foo f3{};
        auto const finc_auto = &foo::increment_by;
        (f3.*finc_auto)(3);
        auto const val3 = f3.x;
        assert(3 == val3);
    }
}
} // example_03


#include <iostream>
int main() {
    std::cout << "exaple_01 => "; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "exaple_02 => "; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "exaple_03 => "; example_03::run(); std::cout << std::endl << std::endl;

    return 0;
}

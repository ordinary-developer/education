#include <generator>
#include <ranges>
#include <iostream>


std::generator<int> fib() {
    co_yield 0;
    auto a = 0;
    auto b = 1;
    for (auto n : std::views::iota(0)) {
        auto next = a + b;
        a = b;
        b = next;
        co_yield next;
    }
}

std::generator<int> getGenerator() {
    return fib();
}

std::generator<int> getElements() {
    co_yield std::ranges::elements_of(fib());
}


int main() {
    std::cout << std::endl;

    for (auto f : getGenerator() | std::views::take(10)) {
        std::cout << f << " ";
    }
    std::cout << std::endl;    

    for (auto f : getElements() | std::views::take(10)) {
        std::cout << f << " ";
    }
    std::cout << std::endl;
}

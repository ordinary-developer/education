#include <cassert>
namespace test_01 { // base Fibonacci implementation

unsigned int fib(unsigned int const n) {
    return (0 == n 
            ? 0
            : (1 == n) ? 1 : fib(n - 1) + fib(n - 2));
}

void run() {
    assert(1597 == fib(17));
}

} // test_01


#include <vector>
#include <cassert>
namespace test_02 { // Fibonacci implementation with caching

std::vector<unsigned int> cache{0, 1};

unsigned int fib(unsigned int const n) {
    if (cache.size() > n) {
        return cache[n];
    }
    else {
        auto const ret = fib(n - 1) + fib(n - 2);
        cache.push_back(ret);
        return ret;
    }
}

void run() {
    assert(1597 == fib(17));
}

} // test_02


#include <stdexcept>
#include <vector>
#include <cassert>
#include <cstddef>
namespace test_03 { // efficient cahce for calculating Fibonacci numbers

class fib_cache {
public:
    fib_cache() 
        : m_previous{0}, m_last{1}, m_size{2} {}

    std::size_t size() const { return m_size; }

    unsigned int operator[](unsigned int const n) const {
        return (n == m_size - 1 
                ? m_last
                : (n == m_size -2 ? m_previous : throw std::out_of_range("the value is not longer in the cache")));
    }

    void push_back(unsigned int const value) {
        m_size++;
        m_previous = m_last;
        m_last = value;
    }

private:
    unsigned int m_previous;
    unsigned int m_last;
    std::size_t m_size;
} cache{};

unsigned int fib(unsigned int const n) {
    if (cache.size() > n) {
        return cache[n];
    }
    else {
        auto const ret = fib(n - 1) + fib(n - 2);
        cache.push_back(ret);
        return ret;
    }
}

void run() {
    assert(1597 == fib(17));
}

} // test_03


#include <iostream>
int main() {
    std::cout << "test 01 => [ok]" << std::endl; test_01::run(); std::cout << std::endl;
    std::cout << "test 02 => [ok]" << std::endl; test_02::run(); std::cout << std::endl;
    std::cout << "test 03 => [ok]" << std::endl; test_03::run(); std::cout << std::endl;

    return 0;
}

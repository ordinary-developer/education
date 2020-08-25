#include <assert.h>

unsigned int fib(const unsigned int n) {
    return 0 == n || 1 == n ? n : fib(n - 1) + fib(n - 2);
}

int main(void) {
    assert(0 == fib(0));
    assert(1 == fib(1));
    assert(55 == fib(10));

    return 0;
}
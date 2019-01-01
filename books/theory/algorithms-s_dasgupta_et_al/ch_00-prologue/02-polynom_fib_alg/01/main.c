#include <assert.h>
#include <stdlib.h>

unsigned int fib(const unsigned int n) {
    // memory allocation
    const unsigned int size = n + 1;
    unsigned int* p_fib_values = (unsigned int*)malloc(size * sizeof(unsigned int));
    if (!p_fib_values) 
        return 0;

    // alg body
    p_fib_values[0] = 0;
    p_fib_values[1] = 1;
    for (unsigned int i = 2; i < size; ++i) 
        p_fib_values[i] = p_fib_values[i - 1] + p_fib_values[i - 2];
    const unsigned int result = p_fib_values[n];
    
    // memory deallocation
    free(p_fib_values);
    
    return result;
}

int main(void) {
    assert(0 == fib(0));
    assert(1 == fib(1));
    assert(55 == fib(10));

    return 0;
}
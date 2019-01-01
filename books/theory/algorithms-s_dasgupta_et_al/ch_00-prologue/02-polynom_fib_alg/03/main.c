#include <assert.h>
#include <stdlib.h>

int fib(const int n) {
    // memory allocation
    const int size = n + 1;
    int* p_fib_values = (int*)malloc(size * sizeof(int));
    if (!p_fib_values) 
        return -1;

    // alg body
    p_fib_values[0] = 0;
    p_fib_values[1] = 1;
    for (unsigned int i = 2; i < size; ++i) 
        p_fib_values[i] = p_fib_values[i - 1] + p_fib_values[i - 2];
    const int result = p_fib_values[n];
    
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
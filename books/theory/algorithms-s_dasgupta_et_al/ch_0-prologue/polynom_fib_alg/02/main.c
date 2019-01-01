#include <assert.h>
#include <stdlib.h>

typedef struct Result {
    int was_error;
    unsigned int value;    
} Result;

Result fib(const unsigned int n) {
    Result result = { .was_error = 1, .value = 0 };

    // memory allocation
    const unsigned int size = n + 1;
    unsigned int* p_fib_values = (unsigned int*)malloc(size * sizeof(unsigned int));
    if (!p_fib_values) 
        return result;

    // alg body
    p_fib_values[0] = 0;
    p_fib_values[1] = 1;
    for (unsigned int i = 2; i < size; ++i) 
        p_fib_values[i] = p_fib_values[i - 1] + p_fib_values[i - 2];
    result = (Result){ .was_error = 0, .value = p_fib_values[n] };
    
    // memory deallocation
    free(p_fib_values);
    
    return result;
}

int main(void) {
    Result fib_0 = fib(0);
    assert(!fib_0.was_error);
    assert(0 == fib_0.value);

    Result fib_1 = fib(1);
    assert(!fib_1.was_error);
    assert(1 == fib_1.value);

    Result fib_10 = fib(10);
    assert(!fib_10.was_error);
    assert(55 == fib_10.value);

    return 0;
}
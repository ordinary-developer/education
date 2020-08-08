#include <cstdlib>
#include <climits>

template <int N>
class SomeClass { };

int main() {
    int A = rand();
    // will not be compiled
    // SomeClass<A> s;
    
    const int B = rand();
    // will not be compiled
    // SomeClass<B> s;

    static const int C = 2;
    SomeClass<C> s; // OK

    SomeClass<(27 + 56 * 5) % 4> s1;
    SomeClass<sizeof(void*) * CHAR_BIT> s2;

    return 0;
}

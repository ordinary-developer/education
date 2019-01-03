#include <assert.h>

unsigned int mult(const unsigned int x, const unsigned int y) {
    if (0 == y)
        return 0;

    const unsigned int z = mult(x, y >> 1);
    return 0 == y % 2 ? 2 * z : x + 2 * z;
}

int main(void) {
    assert(0 == mult(0, 0));
    assert(0 == mult(0, 1));
    assert(50 == mult(5, 10));

    return 0;
}
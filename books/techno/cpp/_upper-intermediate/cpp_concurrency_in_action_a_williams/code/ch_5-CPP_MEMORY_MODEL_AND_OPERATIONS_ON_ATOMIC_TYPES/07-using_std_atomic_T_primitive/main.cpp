#include <atomic>
#include <cassert>

class Foo { };

int main() {
    Foo some_array[5];
    std::atomic<Foo*> p(some_array);

    Foo* x = p.fetch_add(2);
    assert(x == some_array);
    assert(x == &some_array[0]);
    assert(p.load() == &some_array[2]);

    x = (p -= 1);
    assert(x == &some_array[1]);
    assert(p.load() == &some_array[1]);

    return 0;
}

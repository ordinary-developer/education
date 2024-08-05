#include <atomic>
#include <iostream>
#include <cassert>

int main()
{
    if (std::atomic<int>::is_always_lock_free) {
        assert(std::atomic<int>().is_lock_free());
    }
}

#include <atomic>
#include <iostream>
#include <cassert>

template <typename T>
T fetch_mult(std::atomic<T>& shared, T mult) {
    T oldValue = shared.load();
    while (not shared.compare_exchange_strong(oldValue, oldValue * mult)) {
        (void)(0);
    }
    return oldValue; 
}

int main() {
    std::atomic<int> myInt{5};
    std::cout << myInt << '\n';
    fetch_mult(myInt, 5);
    std::cout << myInt << '\n';
}

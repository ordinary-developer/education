#include <atomic>
#include <iostream>


template <typename T>
T fetch_mult(std::atomic<T> & shared, T mult) {
    T oldVal = shared.load();
    while (not shared.compare_exchange_strong(oldVal, oldVal * mult));
    return oldVal;
}


int main() {
    std::atomic<int> myInt{5};
    std::cout << myInt << std::endl;
    fetch_mult(myInt, 5);
    std::cout << myInt << std::endl;
}

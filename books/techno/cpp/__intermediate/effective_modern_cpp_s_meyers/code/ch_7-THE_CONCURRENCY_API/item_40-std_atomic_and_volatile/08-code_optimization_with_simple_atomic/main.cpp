#include <atomic>

int main() {
    std::atomic<int> x = 0;

    // the next code
    std::atomic<int> y(x.load());
    y.store(x.load());

    // can be converted to
    /*
    register = x.load();
    std::atomic<int> y(register);
    y.store(register);
    */

    return 0;
}

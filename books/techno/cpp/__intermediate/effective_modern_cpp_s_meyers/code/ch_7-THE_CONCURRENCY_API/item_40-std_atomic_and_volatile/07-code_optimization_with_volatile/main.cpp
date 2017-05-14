int main() {
    volatile int x = 0;

    // the next code will not be optimized
    auto y = x;
    y = x;
    x = 10;
    x = 20;

    return 0;
}

int main() {
    int x = 0;

    // the next code
    auto y = x;
    y = x;
    x = 10;
    x = 20;
    // may be converted to
    /*
    auto y = x;
     x = 20;
    */

    return 0;
}

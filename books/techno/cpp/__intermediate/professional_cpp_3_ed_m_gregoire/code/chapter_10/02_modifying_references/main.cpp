auto main() -> int {
    int x = 3, y = 4;
    int& xRef = x;
    xRef = y;

    int x1 = 3, y1 = 4;
    int& xRef1 = x1;
    // will ont compile
    // xRef = &y;
    
    int x2 = 3, z2 = 5;
    int& xRef2 = x2;
    int& zRef2 = z2;
    zRef2 = xRef2;

    return 0;
}

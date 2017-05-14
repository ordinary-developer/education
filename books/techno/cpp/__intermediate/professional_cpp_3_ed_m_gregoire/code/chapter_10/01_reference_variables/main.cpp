auto main() -> int {
    int x = 3;
    int& xRef = x;
    xRef = 10;
    // will not compile
    // int& emptyRef;
    
    // will not compile
    //int& unnamedRef1 = 5;
    // but this will be compiled
    const int& unnamedRef2 = 5;

    return 0;
}

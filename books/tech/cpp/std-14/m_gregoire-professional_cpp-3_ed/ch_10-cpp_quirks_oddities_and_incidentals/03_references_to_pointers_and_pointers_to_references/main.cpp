auto main() -> int {
    int* intP;
    int*& ptrRef = intP;
    ptrRef = new int;
    *ptrRef = 5;

    int x = 3;
    int& xRef = x;
    int* xPtr = &xRef;
    *xPtr = 100;

    return 0;
}

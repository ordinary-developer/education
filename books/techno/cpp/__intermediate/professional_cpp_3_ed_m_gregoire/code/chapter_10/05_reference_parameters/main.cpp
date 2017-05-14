void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

void swap_2(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void refcall(int& t) { ++t; }

auto main() -> int {
    int x = 5, y = 6;
    swap(x, y);

    // will not compile
    // swap(3, 4);
    
    int x2 = 5, y2 = 6;
    int* xp = &x2;
    int* yp = &y2;
    swap(*xp, *yp);

    swap_2(&x2, &y2);
    // will not compile
    // swap_2(3, 4);
    
    int* ptr = (int*)8;
    // will compile but then will crash
    // refcall(*ptr);

    return 0;
}

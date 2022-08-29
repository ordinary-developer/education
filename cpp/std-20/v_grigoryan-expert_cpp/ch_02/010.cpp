#include <iostream>

int sum(const int n, const int m) {
    return n + m;
}

int max(const int x, const int y) {
    int res = x > y ? x : y;
    return res;
}

int calc(const int a, const int b) {
    return sum(a, b) + max(a, b);
}


int main() {
    calc(11, 22);
}
    
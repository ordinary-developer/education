#include <iostream>

void set_2d_1(float* a, int m, int i, int j) {
    a[i*m + j] = a[i*m + j] * a[i*m + i] + a[i*m + j]; //opps
}

void set_2d_2(float* a, int m, int i, int j) {
    float &r = a[i*m+j];
    r = r * r + r;
}



int main()
{
    float array[] = { 1.0, 2.0, 3.0 };

    set_2d_1(array, 0, 0, 1);

    set_2d_2(array, 0, 0, 1);

    return 0;
}
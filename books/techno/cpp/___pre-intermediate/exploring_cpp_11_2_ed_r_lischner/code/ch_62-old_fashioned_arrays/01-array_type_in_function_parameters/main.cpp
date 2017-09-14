#include <iostream>

int sum(int* array, int size);

int main() {
    int data[5] { 1, 2, 3, 4, 5 };
    std::cout << sum(data, 5) << '\n';

    return 0;
}

int sum(int array[], int size) {
    int result{0};
    while (0 != size--)
        result += array[size];
    return result;
}

#include <iostream>
#include <thread>


int main() {
    int arr[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << *(arr + 2) << std::endl;

    std::cout << *(arr + 0) << std::endl;
    std::cout << *arr << std::endl;
    std::cout << arr[0] << std::endl;

    std::cout << *(2 + arr) << std::endl;
    std::cout << 2[arr] << std::endl;

    int * arr2 = new int[10];
    arr[4] = 2;
    delete [] arr2;    
}

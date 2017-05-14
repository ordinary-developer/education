#include <iostream>

template <typename T>
void swap(T& a, T& b) {
    T temp(a);
    a = b;
    b = temp;
}


int main()
{
    int x = 1, y = 2;
    swap(x, y);

    int grades[] = { 1, 2, 3 };
    swap(grades[1], grades[2]);
    for (auto& element: grades) {
        std::cout << element << std::endl;
    }

    return 0;
}
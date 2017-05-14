#include <iostream>

int main()
{
    int a = 12;
    int &ra = a;   // ra is another name for a
    --ra;          // a == 11
    a = 10;        // ra == 10
    int* ip = &ra; // ip points to a  

    std::cout << &ra << " " << &a << std::endl;
     
    return 0;
}
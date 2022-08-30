#include <iostream>


int main(){
    int answer = 42;
    std::cout << &answer << std::endl;

    int * ptr0 = &answer;

    int ivar = 26;
    char ch = 't';
    double d = 3.14;

    int * ptr = &ivar;
    char * pch = &ch;
    double * pd = &d;

    std::cout << *ptr << std::endl; // prints 26

    char * p = (char*)&ivar;
    std::cout << int{*p} << std::endl; // the first byte
    std::cout << int{ *(p + 1) } << std::endl; // the second byte
    std::cout << int{ *(p + 2) } << std::endl; // the third byte
    std::cout << int{ *(p - 1) } << std::endl; // the previous byte

    short * sh = (short*)&ivar;
    std::cout << int{ *sh } << std::endl; // value in the first two bytes of ivar
    std::cout << int{ *(sh + 1) } << std::endl; // value in the last two bytes of ivar

    std::cout << sizeof(ptr) << " = " << sizeof(pch) << " = " << sizeof(pd);
}

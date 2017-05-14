#include <iostream>
using namespace std;



int main()
{  
    const int theAnswer = 42;

    // IDE will show that 
    // x's deduced type is "int"
    // y's deduced type is "const int*"
    auto x = theAnswer;
    auto y = &theAnswer;

    return 0;
}
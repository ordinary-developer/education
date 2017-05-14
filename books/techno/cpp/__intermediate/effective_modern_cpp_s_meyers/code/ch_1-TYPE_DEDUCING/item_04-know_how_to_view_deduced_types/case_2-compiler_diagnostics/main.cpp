#include <iostream>
using namespace std;


template <typename T>
class TD;

int main()
{  
    const int theAnswer = 42;
    auto x = theAnswer;
    auto y = &theAnswer;
    
    // here compile errors will be
    TD<decltype(x)> xType;
    TD<decltype(y)> yType;
    // from the compiler we can know
    // main.cpp(15) : error C2079: 'xType' uses undefined class 'TD<int>'
    // main.cpp(16) : error C2079: 'yType' uses undefined class 'TD<const int *>'

    return 0;
}
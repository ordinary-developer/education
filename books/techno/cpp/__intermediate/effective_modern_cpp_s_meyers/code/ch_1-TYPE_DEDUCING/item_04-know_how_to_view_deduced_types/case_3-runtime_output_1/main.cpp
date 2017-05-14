#include <iostream>
using namespace std;

int main()
{  
    const int theAnswer = 42;
    auto x = theAnswer;
    auto y = &theAnswer;

    cout << typeid(x).name() << '\n';
    cout << typeid(y).name() << '\n';

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Widget { };

template <typename T>
void f(const T& parameter) 
{
    cout << "T = " << typeid(T).name() << '\n';
    cout << "parameter = " << typeid(parameter).name() << '\n';
    
}


vector<Widget> createVector() {
    Widget widget;
    vector<Widget> vec;
    vec.push_back(widget);
    return vec;
}

int main()
{  
    const auto vw = createVector();
    if (!vw.empty()) {
        f(&vw[0]);
    }
    return 0;
}
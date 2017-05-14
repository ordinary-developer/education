#include <iostream>
using namespace std;

// Given a name or an expression,
// "decltype" tells you the name's or the expression's type

// "decltype(w)" is "const Widget&"
// "decltype(f)" is "bool(const Widget&)
class Widget { };
bool f(const Widget& w) { }

// simplified version of std::vector
template <typename T>
class vector {
public:
    T& operator[](std::size_t index) { return _value; }
private:
    T _value;
};

int main()
{
    // "decltype(i)" is const int
    const int i = 0;
    
  
    
    // "decltype(Point::x)" is "int"
    // "decltype(Point::y)" is "int"
    struct Point {
        int x, y;
    };
    
    // "decltype(w)" is "Widget"
    Widget w;
    
    // "decltype(w)" is "Widget"
    if (f(w)) {
        
    }
    
    // "decltype(v)" is "vector<int>"
    vector<int> v;
    
    // "decltype(v[0])" is "int&"
    if (v[0] == 0) {
    
    }
    
    return 0;
}
#include <list>

class Widget { };

template <typename T>
class MyAlloc { };

// with aliases
template <typename T>
using MyAllocList1 = std::list<T, MyAlloc<T>>;

// with typedefs
template <typename T>
struct MyAllocList2 {
    typedef std::list<T, MyAlloc<T>> type;
};

int main() {
    // a client code (will not compile)
    // MyAllocList1<Widget> lw1;
    
    // a client code (will not compile)
    // MyAllocList2<Widget>::type lw2;
}


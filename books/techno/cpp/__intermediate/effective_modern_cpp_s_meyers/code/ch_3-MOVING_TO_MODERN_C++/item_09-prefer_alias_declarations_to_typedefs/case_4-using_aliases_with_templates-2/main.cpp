#include <list>

template <typename T>
class MyAlloc { };

// with alias
template <typename T>
using MyAllocList1 = std::list<T, MyAlloc<T>>;

template <typename T>
class Widget1 {
    private:
        MyAllocList1<T> list;
};


// with typedef
template <typename T>
struct MyAllocList2 {
    typedef std::list<T, MyAlloc<T>> type;
};

template <typename T>
class Widget2 {
    private:
        typename MyAllocList2<T>::type list;
};

int main() {
}

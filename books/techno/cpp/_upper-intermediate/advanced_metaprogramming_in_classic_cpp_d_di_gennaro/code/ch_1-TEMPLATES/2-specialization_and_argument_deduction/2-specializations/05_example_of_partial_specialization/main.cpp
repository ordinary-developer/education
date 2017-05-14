namespace example1 {

template <typename T, int N>
class MyClass { };

template <typename T>
class MyClass<T, 0> { };

template <typename T, int N>
class MyClass<T*, N> { };

void run() {
    // here an error will be
    // MyClass<void*, 0> m;    
}

}
//-------------------
namespace example2 {

template <typename T, int N>
class MyClass { };

template <typename T>
class MyClass<T, 0> { };

template <typename T, int N>
class MyClass<T*, N> { };

template <typename T>
class MyClass<T*, 0> { };

void run() {
    // allright here
    MyClass<void*, 0> m;    
}

}


int main() { 
    example1::run();
    example2::run();

    return 0;
}

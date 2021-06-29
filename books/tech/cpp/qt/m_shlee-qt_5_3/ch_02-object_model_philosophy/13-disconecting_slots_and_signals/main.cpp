#include "MyClass.hpp"

int main() {
    MyClass myClass;

    QObject::connect(&myClass, &MyClass::mySignal,
                     &myClass, &MyClass::mySlot);
    myClass.start();

    QObject::disconnect(&myClass, &MyClass::mySignal,
                        &myClass, &MyClass::mySlot);
    myClass.start();

    return 0;
}

#include "MyClass.hpp"
#include <memory>

int main() {
    std::unique_ptr<MyClass> myClass = std::make_unique<MyClass>(); 

    QObject::connect(myClass.get(), &MyClass::mySignal,
                     myClass.get(), &MyClass::mySlot);
    myClass->start();

    return 0;
}

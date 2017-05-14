#pragma once

#include <QObject>

#include <iostream>

class MyClass : public QObject {
    Q_OBJECT
    public:
        MyClass() : QObject() {
          QObject::connect( 
            this,
            static_cast<void (MyClass::*)()>(&MyClass::mySignal),
            this,
            static_cast<void (MyClass::*)()>(&MyClass::mySlot));

          QObject::connect( 
            this,
            static_cast<void (MyClass::*)(int)>(&MyClass::mySignal),
            this,
            static_cast<void (MyClass::*)(int)>(&MyClass::mySlot));

          QObject::connect( 
            this,
            static_cast<void (MyClass::*)(int)>(&MyClass::mySignal),
            static_cast<void (MyClass::*)()>(&MyClass::mySignal));

          QObject::connect(
            this,
            static_cast<void (MyClass::*)()>(&MyClass::mySignal),
            this,
            &MyClass::commonSlot);

          start();

        }

        void start() {
            emit mySignal(3);
        }

    public slots:
        void mySlot(int) { }
        void mySlot() { }
        void commonSlot() {
            std::cout << "pam-pam-pam\n";
        }

    signals:
        void mySignal(int);
        void mySignal();
};

#pragma once

#include <iostream>
#include <QObject>

class MyClass : public QObject {
    Q_OBJECT
    public:
        MyClass() : QObject() {
            QObject::connect(this, &MyClass::mySignal,
                             this, &MyClass::mySlot);
        }

        void start() {
            emit signalMethod(3);
        }

    public slots:
        void mySlot() { 
            std::cout << "The signal has been received\n";
        }

    signals:
        void signalMethod(int);
        void mySignal();

    public:
};


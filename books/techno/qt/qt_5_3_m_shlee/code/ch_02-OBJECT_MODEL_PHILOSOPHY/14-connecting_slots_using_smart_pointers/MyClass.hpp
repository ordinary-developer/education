#pragma once

#include <QObject>
#include <iostream>

class MyClass : public QObject {
    Q_OBJECT
    public:
        void start() {
            emit mySignal();
        }

    public slots:
        void mySlot() {
            std::cout << "beginning of work" << std::endl;
        }

    signals:
        void mySignal();
};

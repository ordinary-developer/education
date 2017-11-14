#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <QtCore>

class MyClass : public QObject {
    Q_OBJECT

    signals:
        void signal1();
        void signal2();

    public slots:
        void slot() {
            qDebug() << "I have processed a signal";
        }

    public:
        MyClass() {
            QObject::connect(this, SIGNAL(signal1()), 
                                   SIGNAL(signal2()));
            QObject::connect(this, SIGNAL(signal2()), SLOT(slot()));
        }

        void sendSignal() {
            emit signal1();
        }
};

#endif

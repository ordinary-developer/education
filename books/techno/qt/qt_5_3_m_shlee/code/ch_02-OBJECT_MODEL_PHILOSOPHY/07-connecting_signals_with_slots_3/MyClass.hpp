#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <QtCore>

class MyClass : public QObject {
    Q_OBJECT
        
    signals:
        void signal();

    public slots:
        void slot() {
            qDebug() << "I have processed a signal";
        }

    public:
        MyClass() {
            connect(this, SIGNAL(signal()), SLOT(slot()));
        }

        void sendSignal() { emit signal(); }
};

#endif

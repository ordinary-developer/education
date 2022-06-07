#pragma once

#include <QObject>
#include <QtCore>

class Counter : public QObject {
    Q_OBJECT
    public:
        Counter();

    public slots:
        void slotInc();

    signals:
        void goodbye();
        void counterChanged(int);

    private:
        int _value;
};

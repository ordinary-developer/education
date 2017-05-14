#ifndef SENDER_HPP
#define SENDER_HPP

#include <QtCore>

class Sender : public QObject {
    Q_OBJECT

    signals:
        void signal();

    public:
        void sendSignal() { emit signal(); }
};

#endif

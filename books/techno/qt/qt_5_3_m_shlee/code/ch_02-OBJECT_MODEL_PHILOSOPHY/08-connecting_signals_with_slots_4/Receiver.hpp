#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#include <QtCore>

class Receiver : public QObject {
    Q_OBJECT

    public slots:
        void slot() { 
            qDebug() << "I have processed a signal";
        }
};

#endif

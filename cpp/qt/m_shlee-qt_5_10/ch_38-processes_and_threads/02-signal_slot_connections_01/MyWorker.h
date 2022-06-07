#pragma once

#include <QtWidgets>

class MyWorker : public QObject {
Q_OBJECT
private:
    int m_nValue;
    QTimer* m_pTimer;
    
public:
    MyWorker(QObject* parentObj = nullptr) : QObject{parentObj}, m_nValue{10} {
        m_pTimer = new QTimer{this};
        QObject::connect(m_pTimer, &QTimer::timeout, this, &MyWorker::setNextValue);
    }
    
signals:
    void valueChanged(int);
    void finished();
    
public slots:
    void slotDoWork() {
        m_pTimer->start(1000);
    }
    
private slots:
    void setNextValue() {
        emit valueChanged(--m_nValue);
        
        if (not m_nValue) {
            m_pTimer->stop();
            emit finished();
        }
    }
};

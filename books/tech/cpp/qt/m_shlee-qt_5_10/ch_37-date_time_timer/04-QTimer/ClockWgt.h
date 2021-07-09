#pragma once

#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QString>
class ClockWgt : public QLabel {
    Q_OBJECT
    
    public:
        ClockWgt(QWidget * parentWgt = nullptr) : QLabel{ parentWgt } {
            QTimer * timer = new QTimer{this};
            QObject::connect(timer, &QTimer::timeout, this, &ClockWgt::slotUpdateDateTime);
            timer->start(500);
            slotUpdateDateTime();
        }
        
    public slots:
        void slotUpdateDateTime() {
            const QString str = 
                QDateTime::currentDateTime().toString(Qt::SystemLocaleLongDate);
            setText("<h2><center>" + str + "</center></h2>");
        }
};

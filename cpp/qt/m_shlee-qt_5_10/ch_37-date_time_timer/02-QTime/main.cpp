#include <QTime>
#include <QDebug>
namespace example {
    
void run() {
    {
        QTime time{ 20, 4 };
        qDebug() << "hours:" << time.hour() << "minutes:" << time.minute()
            << "seconds:" << time.second() << "msecs:" << time.msec();
        
        QTime timeAux;
        timeAux.setHMS(20, 4, 23, 3);
        qDebug() << "hours:" << timeAux.hour() << "minutes:" << timeAux.minute()
            << "seconds:" << timeAux.second() << "msecs:" << timeAux.msec();
    }
    
    {
        QString str{};
        QTime time{ 20, 4, 23, 3 };
        
        str = time.toString(Qt::TextDate);
        qDebug() << str;
        
        str = time.toString(Qt::ISODate);
        qDebug() << str;
        
        str = time.toString("hh:mm:ss.zzz");
        qDebug() << str;
        
        str = time.toString("h:m:s ap");
        qDebug() << str;
    }
    
    {
        QTime time{ QTime::fromString("20:04:23", Qt::ISODate) };
        qDebug() << time.toString(Qt::ISODate);
    }
    
    {
        QTime time{ 20, 4, 23, 3 };
        
        QTime time2 = time.addSecs(5);
        qDebug() << time2.toString(Qt::ISODate);
        
        QTime time3 = time.addMSecs(15);
        qDebug() << time3.toString("hh:mm:ss.zzz");
    }
    
    {
        QTime time{};
        time.start();
        for (int i = 0; i < 1000; ++i) {}
        qDebug() << "time working" << time.elapsed() << "ms";
    }
}
} // example


#include <QDebug>
int main(int, char**) {
    qDebug() << "example => "; example::run(); qDebug() << "";
    
    return 0;
}

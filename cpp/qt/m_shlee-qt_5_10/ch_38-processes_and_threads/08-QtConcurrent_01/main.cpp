#include <QtCore>
#include <QtConcurrent/QtConcurrent>
#include <QString>

QString myToUpper(QString const& str) { return str.toUpper(); }


#include <QDebug>
int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {  
    QFuture<QString> future = QtConcurrent::run(myToUpper, QString("test"));
    future.waitForFinished();
    qDebug() << future.result();
    
    return 0;
}

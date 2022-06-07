#include <QtCore>
#include <QtConcurrent/QtConcurrent>
#include <QString>

QString myToUpper(QString const& str) { return str.toUpper(); }


#include <QDebug>
#include <QStringList>
int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {  
    QStringList list{ QStringList{} << "one" << "two" << "three" };
    QFuture<QString> future = 
        QtConcurrent::mapped(list.begin(), list.end(), myToUpper);
    future.waitForFinished();
    
    qDebug() << future.results();
    
    return 0;
}

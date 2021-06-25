#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QTest>
namespace workspace {
void run() {
    QString const srcStr{ "this is a text\r\nthis is a text\r\nthis is a text" };
    QFile file{ "file.txt" };
    
    // write text data to a file
    if (not file.open(QIODevice::WriteOnly)) 
        return;
    
    QTextStream streamToWrite{ &file };
    streamToWrite << srcStr;
    
    file.close();
    if (QTextStream::Ok != streamToWrite.status())
        qDebug() << "error on writing";
    
    // read a file by lines
    if (not file.open(QIODevice::ReadOnly))
        return;
    
    QTextStream lineStream{ &file };
    QString strLines;
    while (not lineStream.atEnd()) {
        QString const& str = lineStream.readLine();
        qDebug() << QString{ "[%0]" }.arg(str);
        
        if (not strLines.isEmpty())
            strLines.append("\r\n");
        strLines.append(str);
    }
    
    file.close();
    if (QTextStream::Ok != lineStream.status())
        qDebug() << "error on line-by-line reading";
    
    QCOMPARE(srcStr, strLines);
    
    // read the whole file
    if (not file.open(QIODevice::ReadOnly))
        return;
    
    QTextStream allStream{ &file };
    QString const& allStr = allStream.readAll();
    file.close();
    
    if (QTextStream::Ok != allStream.status())
        qDebug() << "error on the whole reading";
    
    QCOMPARE(srcStr, allStr);
    
    // clear
    if (file.exists())
        file.remove();
}
} // workspace


#include <QTest>
class TestClass : public QObject {
Q_OBJECT
private slots:
    void run() { workspace::run(); }
};


QTEST_MAIN(TestClass)
#include "main.moc"

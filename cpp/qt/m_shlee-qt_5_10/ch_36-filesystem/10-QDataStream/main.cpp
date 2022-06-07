#include <QTest>
#include <QFile>
#include <QPointF>
#include <QImage>
#include <QDebug>
namespace workspace { 
void run() {
    QFile file{ "file.bin" };
    
    // write binary data to a file
    if (not file.open(QIODevice::WriteOnly))
        return;
    
    QDataStream streamToWrite{ &file };
    streamToWrite.setVersion(QDataStream::Qt_5_3);
    streamToWrite << QPointF{ 42, 17 } << QImage{ ":/img" };
    
    file.close();
    if (QDataStream::Ok != streamToWrite.status())
        qDebug() << "error on writing";
    
    
    // read binary data from a file
    if (not file.open(QIODevice::ReadOnly))
        return;
    
    QPointF pt{};
    QImage img{};
    QDataStream streamToRead{ &file };
    streamToRead.setVersion(QDataStream::Qt_5_3);
    streamToRead >> pt >> img;
    
    if (QDataStream::Ok != streamToRead.status())
        qDebug() << "error on reading";
    
    file.close();
    
    // assert
    QCOMPARE(42, pt.x());
    QCOMPARE(17, pt.y());    
    QCOMPARE(QImage{ ":/img" }.size(), img.size());
    
    // clear
    if (file.exists())
        file.remove();
}
} // example_01


#include <QTest>
class TestClass : public QObject {
Q_OBJECT
private slots:
    void run() { workspace::run(); }
};


QTEST_MAIN(TestClass)
#include "main.moc"

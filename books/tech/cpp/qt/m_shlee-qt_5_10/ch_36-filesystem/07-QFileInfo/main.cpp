#include <QString>
#include <QFileInfo>
#include <QDateTime>
#include <QDebug>

int main(int, char**) { 
    qDebug() << 
        QString{ "isFile: [%0], isDir: [%1], isSymLink: [%2]" }
            .arg(
                QString::number(QFileInfo{}.isFile()),
                QString::number(QFileInfo{}.isDir()),
                QString::number(QFileInfo{}.isSymLink()));
        
    qDebug() << 
        QString{ "absPath: [%0], filePath: [%1], fileName: [%2], baseName: [%3], suffix: [%4]" }
            .arg(
                QFileInfo{}.absoluteFilePath(),
                QFileInfo{}.filePath(),
                QFileInfo{}.fileName(),
                QFileInfo{}.baseName(),
                QFileInfo{}.completeSuffix());
    
    qDebug() << 
        QString{ "created: [%0], lastModified: [%1], lastRead: [%2]" }
            .arg(
                QFileInfo{}.created().toString(),
                QFileInfo{}.lastModified().toString(),
                QFileInfo{}.lastRead().toString());
            
    qDebug() << 
        QString{ "readable: [%0], writable: [%1], hidden: [%2], executable: [%3]" }
            .arg(
                QString::number(QFileInfo{}.isReadable()),
                QString::number(QFileInfo{}.isWritable()),
                QString::number(QFileInfo{}.isHidden()),
                QString::number(QFileInfo{}.isExecutable()));
            
    auto const getFileSizeRepr = [](qint64 nSize) {
        int i = 0;
        for (; nSize > 1023; nSize /= 1024, ++i) 
            if (i >= 4)
                break;
            
        return QString{}.setNum(nSize) + "BKMGT"[i];
    };
    qDebug() << 
        QString{ "file size: [%0], formatted file size: [%1]" }
            .arg(
                QString::number(QFileInfo{}.size()),
                getFileSizeRepr(QFileInfo{}.size()));
            
    return 0;
}

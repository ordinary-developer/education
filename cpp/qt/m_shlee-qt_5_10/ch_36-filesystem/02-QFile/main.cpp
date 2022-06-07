#include <QFile>
#include <QDebug>
namespace example_01 { // read by blocks
    
void run() {
    // create a file for reading
    {
        QFile file{"src.dat"};
        if (file.exists()) {
            file.remove();
        }
        
        if (not file.open(QIODevice::WriteOnly)) {
            qDebug() << "err on src file opening: fatal err";
            return;
        }
        
        constexpr const int len{1024};
        char data[len];
        if (not file.write(data, len)) {
            qDebug() << "err on src file writing";
        }
        
        file.close();
    }
    
    // read/write
    QFile srcFile{"src.dat"};
    if (not srcFile.open(QIODevice::ReadOnly)) {
        qDebug() << "err on src file opening: fatal err";
        srcFile.remove();
        return;
    }
    
    QFile dstFile{"dst.dat"};
    if (dstFile.exists()) {
        qDebug() << "dst file already exists: it will be rewritten";
    }
    if (not dstFile.open(QIODevice::WriteOnly)) {
        qDebug() << "err on dst file opening: fatal err";
        dstFile.remove();
    }
    
    constexpr const int len{1024};
    char data[len];
    while (not srcFile.atEnd()) {
        int const blockSize = srcFile.read(data, sizeof(data));
        dstFile.write(data, blockSize);
    }
    
    srcFile.close();
    dstFile.close();
    
    
    // clean
    if (not srcFile.remove()) {
        qDebug() << "err on src file removing";
    }
    
    if (not dstFile.remove()) {
        qDebug() << "err on dst file removing";
    }
}
} // example_01


#include <QFile>
#include <QDebug>
namespace example_02 { // -> read "all at once"

void run() {
    // create a file for reading
    {
        QFile file{"src.dat"};
        if (file.exists()) {
            file.remove();
        }
        
        if (not file.open(QIODevice::WriteOnly)) {
            qDebug() << "err on src file opening: fatal err";
            return;
        }
        
        constexpr const int len{1024};
        char data[len];
        if (not file.write(data, len)) {
            qDebug() << "err on src file writing";
        }
        
        file.close();
    }
    
    // read/write
    QFile srcFile{"src.dat"};
    if (not srcFile.open(QIODevice::ReadOnly)) {
        qDebug() << "err on src file opening: fatal err";
        srcFile.remove();
        return;
    }
    
    QFile dstFile{"dst.dat"};
    if (dstFile.exists()) {
        qDebug() << "dst file already exists: it will be rewritten";
    }
    if (not dstFile.open(QIODevice::WriteOnly)) {
        qDebug() << "err on dst file opening: fatal err";
        dstFile.remove();
    }
    
    QByteArray data = srcFile.readAll();
    dstFile.write(data);
    
    srcFile.close();
    dstFile.close();
    
    
    // clean
    if (not srcFile.remove()) {
        qDebug() << "err on src file removing";
    }
    
    if (not dstFile.remove()) {
        qDebug() << "err on dst file removing";
    }
}

} // example_02


#include <QDebug>
int main(int, char**) {
    qDebug() << "example 01 =>"; example_01::run(); qDebug() << "";
    qDebug() << "example 02 =>"; example_02::run(); qDebug() << "";
    
    return 0;
}

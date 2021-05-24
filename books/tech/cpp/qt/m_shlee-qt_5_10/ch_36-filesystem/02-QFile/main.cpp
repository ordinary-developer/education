#include <QDebug>
#include <QFile>
namespace example_01 { // -> block reading
    
void run() {
    // creating a file for reading (copying)
    {
        QFile file1{"file1.dat"};
        if (file1.exists())
            file1.remove();
    
        if (not file1.open(QIODevice::WriteOnly)) {
            qDebug() << "err on file1 opening: fatal err";
            return;
        }
    
        constexpr const int len = 1024;
        char data[len];
        if (not file1.write(data, len)) {
            qDebug() << "err on file1 writing";
        }

        file1.close();
    }
    
    // make reading (make a copy)
    QFile file1{"file1.dat"};
    if (not file1.open(QIODevice::ReadOnly)) {
        qDebug() << "err on file1 opening: fatal err";
        file1.remove();
        return;
    }
    
    QFile file2{"file2.dat"};
    if (file2.exists()) {
        qDebug() << "file2 already exists: it will be rewritten";
    }
    if (not file2.open(QIODevice::WriteOnly)) {
        qDebug() << "err on file2 opening: fatal err";
        file1.remove();
    }
    
    constexpr const int len = 1024;
    char data[len];
    while (not file1.atEnd()) {
        const int blockSize = file1.read(data, sizeof(data));
        file2.write(data, blockSize);
    }
    
    file1.close();
    file2.close();
    
    
    // cleaning
    if (not file1.remove()) {
        qDebug() << "err on file1 removing";
    }
    
    if (not file2.remove()) {
        qDebug() << "err on file2 removing";
    }
}    

} // example_01


#include <QFile>
#include <QDebug>
namespace example_02 { // -> "all at once" reading

void run() {
    // creating a file for reading
    {
        QFile file1{"file1.dat"};
        if (file1.exists()) 
            file1.remove();
        
        if (not file1.open(QIODevice::WriteOnly)) {
            qDebug() << "err on file1 opening: fatal err";
            return;
        }
        
        constexpr const int len = 1024;
        char data[len];
        if (not file1.write(data, len)) {
            qDebug() << "err on file1 writing";
        }
        
        file1.close();
    }
    
    // make reading (make a copy)
    QFile file1{"file1.dat"};
    if (not file1.open(QIODevice::ReadOnly)) {
        qDebug() << "err on file1 opening: fatal err";
        file1.remove();
        return;
    }
    
    QFile file2{"file2.dat"};
    if (file2.exists()) {
        qDebug() << "file2 already exists: it will be rewritten";
    }
    if (not file2.open(QIODevice::WriteOnly)) {
        qDebug() << "err on file2 opening: fatal err";
        file1.remove();
    }
    
    QByteArray data = file1.readAll();
    file2.write(data);
    
    file1.close();
    file2.close();
    
    // cleaning
    if (not file1.remove()) {
        qDebug() << "err on file1 removing";
    }
    if (not file2.remove()) {
        qDebug() << "err on file2 removing";
    }
}

} // example_02
    

int main(int, char**) {
    example_01::run();
    example_02::run();
    
    return 0;
}

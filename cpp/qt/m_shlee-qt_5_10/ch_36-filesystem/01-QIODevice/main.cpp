#include <QIODevice>
#include <QFile>
#include <QDebug>
namespace example { // -> print contents from any QIODevice
    
void print(QIODevice * device) {
    char ch;
    QString str;
    
    device->open(QIODevice::ReadOnly);
    for (; !device->atEnd(); ) {
        device->getChar(&ch);
        str += ch;
    }
    device->close();
    
    qDebug() << str;
}    

void run() {
    QFile file("file.dat");
    if (not file.open(QIODevice::WriteOnly)) {
        qDebug() << "err on creating: fatal err";
        return;
    }
    
    constexpr const int len = 1024;
    char data[len];
    if (file.write(data, len) < 0) {
        qDebug() << "err on writing";
    }
    
    file.close();
    
    print(&file);
    
    if (not file.remove()) {
        qDebug() << "err on removing";
    }
}

} // example


#include <QDebug>
int main(int, char**) {
    qDebug() << "example =>"; example::run(); qDebug() << "";
    
    return 0;
}

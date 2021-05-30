#include <QByteArray>
#include <QBuffer>
#include <QDataStream>
#include <QFile>
#include <QDebug>
namespace example {

void run() {
    QByteArray data{};

    QBuffer buf{&data};
    buf.open(QIODevice::WriteOnly);
    QDataStream out{&buf};
    out << QString{"msg"};

    QFile file{"file.dat"};
    if (not file.open(QIODevice::WriteOnly)) {
        qDebug() << "err with file opening for writing: fatal err";
        return;
    }
    file.write(data);
    file.close();

    QFile::remove(file.fileName());
}

} // example


#include <QDebug>
int main(int, char**) {
    qDebug() << "example =>"; example::run(); qDebug() << "";

    return 0;
}

#include <QByteArray>
#include <QBuffer>
#include <QDataStream>
#include <QFile>
#include <QDebug>


void run() {
    QByteArray data{};

    QBuffer buf{&data};
    buf.open(QIODevice::WriteOnly);
    QDataStream out{&buf};
    out << QString{"msg"};

    QFile file{ "file.dat" };
    if (not file.open(QIODevice::WriteOnly)) {
        qDebug() << "error with file opening for writing";
        return;
    }
    file.write(data);
    file.close();

    QFile::remove(file.fileName());
}


int main(int, char**) {
    run();

    return 0;
}
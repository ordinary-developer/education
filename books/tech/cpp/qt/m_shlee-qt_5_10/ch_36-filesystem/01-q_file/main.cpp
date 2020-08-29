#include <QFile>
#include <QDebug>
namespace example_01 { // -> QFile: setFileName, QFile.isOpen
void run() {
    QFile file{};
    file.setFileName("no_existing_file-aabbccddeeff");
    qDebug() << "file is opened: " << file.isOpen();
}    
} // example_01


#include <QFile>
#include <QDebug>
namespace example_02 { // -> QFile: exists, read, write
void run() {
    char buf[1024] = { 0 };

    QFile file1{ "file1.dat" };
    QFile file2{ "file2.dat" };
    qDebug() << "file1 exists: " << QFile::exists(file1.fileName());
    qDebug() << "file2 exists: " << file2.exists();

    if (not file1.open(QIODevice::WriteOnly)) {
        qDebug() << "error with file1 opening for writing";
        return;
    }
    file1.write(buf, sizeof(buf));
    file1.close();

    if (not file1.open(QIODevice::ReadOnly)) {
        qDebug() << "error with file1 opening for reading";
        return;
    }

    if (not file2.open(QIODevice::WriteOnly)) {
        qDebug() << "error with file2 opening for writing";
        return;
    }

    while (not file1.atEnd()) {
        int const size = file1.read(buf, sizeof(buf));
        file2.write(buf, size);
    }
    file1.close();
    file2.close(); 

    QFile::remove(file1.fileName());
    QFile::remove(file2.fileName());
}
} // example_02


#include <QFile>
#include <QDebug>
namespace example_03 { // -> QFile: readAll
void run() {
    char buf[1024] = { 1 };

    QFile file1{ "file1.dat" };
    QFile file2{ "file2.dat" };

    if (not file1.open(QIODevice::WriteOnly)) {
        qDebug() << "error with file1 opening for writing";
        return;
    }
    file1.write(buf, sizeof(buf));
    file1.close();

    if (not file1.open(QIODevice::ReadOnly)) {
        qDebug() << "error with file1 opening for reading";
        return;
    }

    if (not file2.open(QIODevice::WriteOnly)) {
        qDebug() << "error with file2 opening for writing";
        return;
    }

    QByteArray const& data = file1.readAll();
    file2.write(data);

    file1.close();
    file2.close();

    QFile::remove(file1.fileName());
    QFile::remove(file2.fileName());
}
} // example_03


#include <QDebug>
int main(int, char**) {
    qDebug() << "example_01 =>"; example_01::run(); qDebug() << "";
    qDebug() << "example_02 =>"; example_02::run(); qDebug() << "";
    qDebug() << "example_03 =>"; example_03::run(); qDebug() << "";

    return 0;
}

#include <QTemporaryFile>
#include <QDir>
#include <QApplication>
#include <QDebug>
void run() {
    qDebug() << QDir::tempPath();
    QTemporaryFile tmpFile1{ "tmp_file1" }, tmpFile2{};
    if (tmpFile1.open() and tmpFile2.open()) {
        qDebug() << tmpFile1.fileName();
        qDebug() << tmpFile2.fileName();
    }
}


int main(int, char**) {
    run();

    return 0;
}

#include <QTemporaryFile>
#include <QDir>
#include <QDebug>
namespace example {
    
void run() {
    qDebug() << QDir::tempPath();
    QTemporaryFile tmpFile1{"tmp_file1"}, tmpFile2{};
    if (tmpFile1.open() and tmpFile2.open()) {
        qDebug() << tmpFile1.fileName() << " " << tmpFile2.fileName();
    }
}
} // example


#include <QDebug>
int main(int, char**) {
    qDebug() << "example => "; example::run(); qDebug() << "";
    
    return 0;
}

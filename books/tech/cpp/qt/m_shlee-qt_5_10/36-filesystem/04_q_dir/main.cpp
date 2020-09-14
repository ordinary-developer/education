#include <QDir>
#include <QApplication>
#include <QDebug>
void run() {
    // static QDir methods
    qDebug() << "[current app catalogue] =>" << QDir::current() << "\n";
    qDebug() << "[root catalogue] =>" << QDir::root() << "\n";
    qDebug() << "[node catalogues] =>" << QDir::drives() << "\n";
    qDebug() << "[user catalogue] =>" << QDir::home() << "\n";

    // app catalogue
    qDebug() << "[starting catalogue] =>" << QApplication::applicationDirPath() << "\n";
    qDebug() << "[starting catalogue and app name] =>" << QApplication::applicationFilePath() << "\n";

    // QDir methods
    QDir curDir = QDir::current();
    qDebug() << "curDir exists:" << curDir.exists() << ", curDir name:" << curDir.dirName() << "\n";

    bool ret = curDir.mkdir("subdir");
    qDebug() << "subdir creation:" << ret << "\n";

    ret = curDir.cd("subdir");
    qDebug() << "subdir entering:" << ret << ", dirName:" << curDir.dirName() << "\n";
    
    ret = curDir.cd("..");
    qDebug() << "up entering:" << ret << ", dirName:" << curDir.dirName() << "\n";
    
    ret = curDir.rename("subdir", "new_subdir");
    qDebug() << "subdir renaming:" << ret << "\n";

    ret = curDir.rmdir("new_subdir");
    qDebug() << "subdir deletion:" << ret << "\n";
}


int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    run();

    return 0;
}

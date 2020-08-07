#include <QApplication>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLabel label{ "label" };
    label.show();

    bool const result = QDesktopServices::openUrl(QUrl{"https://www.qt.io"});
    qDebug() << "result: " << result;

    return app.exec();
}
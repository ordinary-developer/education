#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLabel label{ "label" };
    label.show();
    label.move(
        (QApplication::desktop()->width() - label.width()) / 2,
        (QApplication::desktop()->height() - label.height()) / 2);

    return app.exec();
}
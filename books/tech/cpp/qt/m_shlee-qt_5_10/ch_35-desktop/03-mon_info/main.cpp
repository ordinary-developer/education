#include <QApplication>
#include <QLabel>
#include <QDesktopWidget>
#include <QDebug>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLabel lbl{ "label" };
    lbl.show();

    QDesktopWidget* pDesktop = QApplication::desktop();
    for (int i{0}; i < pDesktop->screenCount(); ++i) {
        qDebug() << "screen: " << i;
        qDebug() << "width: " << pDesktop->screenGeometry(i).width();
        qDebug() << "height: " << pDesktop->screenGeometry(i).height();
    }

    return app.exec();
}
#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QTabWidget tab{};
    QStringList list{};

    list << "linux" << "windows" << "macosx" << "android";
    foreach (QString str, list)
        tab.addTab(new QLabel{ str, &tab },
                   QPixmap{":/" + str + ".jpg"},
                   str);

    tab.resize(360, 100);
    tab.show();

    return app.exec();
}

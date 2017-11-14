#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QToolBox toolBox{};
    QStringList list{};

    list << "linux" << "windows" << "macosx" << "android";
    foreach (QString str, list)
        toolBox.addItem(new QLabel{str, & toolBox},
                        QPixmap{":/" + str + ".jpg"},
                        str);

    toolBox.resize(100, 80);
    toolBox.show();

    return app.exec();
}

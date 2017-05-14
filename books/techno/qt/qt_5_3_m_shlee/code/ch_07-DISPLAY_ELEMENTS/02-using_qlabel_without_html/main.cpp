#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QPixmap pixmap{};
    pixmap.load(":/image.jpg");
    QLabel label{};
    label.resize(pixmap.size());
    label.setPixmap(pixmap);
    label.show();

    return app.exec();
}

#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QScrollArea scrollArea{};

    QWidget* widget{new QWidget{}};
    QPixmap pixmap{":/image.jpg"};

    QPalette palette{};
    palette.setBrush(widget->backgroundRole(), QBrush(pixmap));
    widget->setPalette(palette);
    widget->setAutoFillBackground(true);
    widget->setFixedSize(pixmap.width(), pixmap.height());

    scrollArea.setWidget(widget);
    scrollArea.resize(350, 150);
    scrollArea.show();

    return app.exec();
}

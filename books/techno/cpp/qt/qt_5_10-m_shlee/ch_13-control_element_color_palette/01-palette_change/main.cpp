#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QSpinBox spinBox{};

    QPalette palette{ spinBox.palette() };

    palette.setBrush(
        QPalette::Button, QBrush(Qt::red, Qt::Dense3Pattern));
    palette.setColor(
        QPalette::ButtonText, Qt::blue);
    palette.setColor(QPalette::Text, Qt::magenta);
    palette.setColor(QPalette::Active, QPalette::Base, Qt::green);

    spinBox.setPalette(palette);
    spinBox.resize(150, 74);
    spinBox.show();

    app.setStyle("Windows");

    return app.exec();
}

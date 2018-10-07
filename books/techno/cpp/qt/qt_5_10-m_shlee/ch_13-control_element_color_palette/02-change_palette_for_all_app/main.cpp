#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QPalette palette{ Qt::red, Qt::blue };
    QApplication::setPalette(palette);

    QSpinBox spinBox{};
    spinBox.resize(150, 74);
    spinBox.show();

    app.setStyle("Windows");

    return app.exec();
}

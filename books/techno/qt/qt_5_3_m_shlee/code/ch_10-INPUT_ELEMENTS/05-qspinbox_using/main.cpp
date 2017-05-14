#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QSpinBox spinBox{};
    spinBox.setRange(1, 100);
    spinBox.setSuffix(" MB");
    spinBox.setButtonSymbols(QSpinBox::PlusMinus);
    spinBox.setWrapping(true);
    spinBox.show();
    spinBox.resize(100, 30);

    return app.exec();
}

#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};
    QLCDNumber* lcdNumber{ new QLCDNumber{} };
    QSpinBox* spinBox{ new QSpinBox{} };

    lcdNumber->setSegmentStyle(QLCDNumber::Filled);
    lcdNumber->setMode(QLCDNumber::Hex);

    spinBox->setFixedHeight(30);

    QObject::connect(
        spinBox, 
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        lcdNumber, 
        static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));

    QVBoxLayout* layout{ new QVBoxLayout{} };
    layout->addWidget(lcdNumber);
    layout->addWidget(spinBox);
    widget.setLayout(layout);

    widget.resize(250, 150);
    widget.show();

    return app.exec();
}

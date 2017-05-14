#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};
    QLCDNumber* lcdNumber{ new QLCDNumber{4} };
    QScrollBar* scrollBar{ new QScrollBar{Qt::Horizontal} };

    QObject::connect(
        scrollBar, 
        static_cast<void (QScrollBar::*)(int)>(&QScrollBar::valueChanged),
        lcdNumber,
        static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));

    QVBoxLayout* layout{ new QVBoxLayout{} };
    layout->addWidget(lcdNumber);
    layout->addWidget(scrollBar);
    widget.setLayout(layout);

    widget.resize(250, 150);
    widget.show();

    return app.exec();
}

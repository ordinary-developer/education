#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{argc, argv};

    QWidget widget{};
    QPushButton* commandA{new QPushButton{"A"}};
    QPushButton* commandB{new QPushButton{"B"}};

    QBoxLayout* boxLayout{new QBoxLayout{QBoxLayout::LeftToRight}};
    boxLayout->addWidget(commandA, 1);
    boxLayout->addStretch(1);
    boxLayout->addWidget(commandB, 2);
    widget.setLayout(boxLayout);

    widget.resize(450, 40);
    widget.show();

    return app.exec();
}

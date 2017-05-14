#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{argc, argv};

    QWidget widget{};
    QPushButton* commandA{new QPushButton{"A"}};
    QPushButton* commandB{new QPushButton{"B"}};
    QPushButton* commandC{new QPushButton{"C"}};

    QBoxLayout* boxLayout{new QBoxLayout{QBoxLayout::LeftToRight}};
    boxLayout->addWidget(commandA, 1);
    boxLayout->addWidget(commandB, 2);
    boxLayout->addWidget(commandC, 3);
    widget.setLayout(boxLayout);

    widget.resize(450, 40);
    widget.show();

    return app.exec();
}

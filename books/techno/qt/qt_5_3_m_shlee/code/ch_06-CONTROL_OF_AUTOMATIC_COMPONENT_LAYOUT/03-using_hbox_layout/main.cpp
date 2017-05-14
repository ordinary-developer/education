#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{argc, argv};

    QWidget widget{};

    QPushButton* commandA{ new QPushButton{"A"} };
    QPushButton* commandB{ new QPushButton{"B"} };
    QPushButton* commandC{ new QPushButton{"C"} };

    QHBoxLayout* hBoxLayout{ new QHBoxLayout{} };
    hBoxLayout->setMargin(10);
    hBoxLayout->setSpacing(20);
    hBoxLayout->addWidget(commandA);
    hBoxLayout->addWidget(commandB);
    hBoxLayout->addWidget(commandC);
    widget.setLayout(hBoxLayout);

    widget.show();

    return app.exec();
}

#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{argc, argv};

    QWidget widget{};

    QPushButton* commandA{ new QPushButton{"A"} };
    QPushButton* commandB{ new QPushButton{"B"} };
    QPushButton* commandC{ new QPushButton{"C"} };

    QVBoxLayout* vBoxLayout{ new QVBoxLayout{} };
    vBoxLayout->setMargin(10);
    vBoxLayout->setSpacing(20);
    vBoxLayout->addWidget(commandA);
    vBoxLayout->addWidget(commandB);
    vBoxLayout->addWidget(commandC);
    widget.setLayout(vBoxLayout);

    widget.show();

    return app.exec();
}

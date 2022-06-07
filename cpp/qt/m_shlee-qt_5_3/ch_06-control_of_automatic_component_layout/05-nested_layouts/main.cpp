#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};

    QPushButton* commandA{ new QPushButton{"A"} };
    QPushButton* commandB{ new QPushButton{"B"} };
    QPushButton* commandC{ new QPushButton{"C"} };
    QPushButton* commandD{ new QPushButton{"D"} };

    QHBoxLayout* hBoxLayout{ new QHBoxLayout{} };
    hBoxLayout->setMargin(5);
    hBoxLayout->setSpacing(15);
    hBoxLayout->addWidget(commandC);
    hBoxLayout->addWidget(commandD);

    QVBoxLayout* vBoxLayout{ new QVBoxLayout{} };
    vBoxLayout->setMargin(5);
    vBoxLayout->addWidget(commandA);
    vBoxLayout->addWidget(commandB);
    vBoxLayout->addLayout(hBoxLayout);

    widget.setLayout(vBoxLayout);
    widget.show();

    return app.exec();
}

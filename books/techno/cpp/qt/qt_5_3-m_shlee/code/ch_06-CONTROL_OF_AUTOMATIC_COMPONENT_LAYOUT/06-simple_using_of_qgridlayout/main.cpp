#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};

    QPushButton* commandA{ new QPushButton{"A"} };
    QPushButton* commandB{ new QPushButton{"B"} };
    QPushButton* commandC{ new QPushButton{"C"} };
    QPushButton* commandD{ new QPushButton{"D"} };

    QGridLayout* gridLayout{ new QGridLayout{} };
    gridLayout->setMargin(5);
    gridLayout->setSpacing(15);
    gridLayout->addWidget(commandA, 0, 0);
    gridLayout->addWidget(commandB, 0, 1);
    gridLayout->addWidget(commandC, 1, 0);
    gridLayout->addWidget(commandD, 1, 1);
    widget.setLayout(gridLayout);

    widget.show();

    return app.exec();
}

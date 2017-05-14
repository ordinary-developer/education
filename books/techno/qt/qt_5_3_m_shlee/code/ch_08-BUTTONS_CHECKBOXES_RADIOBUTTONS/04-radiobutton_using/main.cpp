#include <QtWidgets>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QGroupBox groupBox{"&Colors"};

    QRadioButton* redButton{ new QRadioButton{"&Red"} };
    QRadioButton* greenButton{ new QRadioButton{"&Green"} };
    QRadioButton* blueButton{ new QRadioButton{"&Blue"} };
    greenButton->setChecked(true);

    QVBoxLayout* layout{ new QVBoxLayout{} };
    layout->addWidget(redButton);
    layout->addWidget(greenButton);
    layout->addWidget(blueButton);
    groupBox.setLayout(layout);

    groupBox.show();

    return app.exec();
}

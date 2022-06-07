#include <QtWidgets>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};
    QLabel* nameLabel{ new QLabel{"&Name:"} };
    QLineEdit* nameLineEdit{ new QLineEdit{} };
    nameLabel->setBuddy(nameLineEdit);

    QLabel* ageLabel{ new QLabel{"&Age:"} };
    QSpinBox* ageSpinBox{ new QSpinBox{} };
    ageLabel->setBuddy(ageSpinBox);

    QVBoxLayout* layout{ new QVBoxLayout{} };
    layout->addWidget(nameLabel);
    layout->addWidget(nameLineEdit);
    layout->addWidget(ageLabel);
    layout->addWidget(ageSpinBox);
    widget.setLayout(layout);

    widget.show();

    return app.exec();
}

#include <QtWidgets>

class NameValidator : public QValidator {
    public:
        NameValidator(QObject* parent) : QValidator(parent) { }

        virtual State validate(QString& str, int& pos) const {
            QRegExp rxp{ QRegExp{"[0-9]"} };
            if (str.contains(rxp))
                return Invalid;
            return Acceptable;
        }
};

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};
    QLabel* textLabel =
        new QLabel{ "&Name (The digits will not be accepted!):" };
    QLineEdit* lineEdit{ new QLineEdit{} };

    NameValidator* nameValidator{ new NameValidator{lineEdit} };
    lineEdit->setValidator(nameValidator);
    textLabel->setBuddy(lineEdit);

    QVBoxLayout* layout{ new QVBoxLayout{} };
    layout->addWidget(textLabel);
    layout->addWidget(lineEdit);
    widget.setLayout(layout);
    widget.show();

    return app.exec();
}

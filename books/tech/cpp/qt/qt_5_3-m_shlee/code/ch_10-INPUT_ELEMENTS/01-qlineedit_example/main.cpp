#include <QtWidgets>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};

    QLabel* labelDisplay{ new QLabel{} };
    labelDisplay->setFrameStyle(QFrame::Box | QFrame::Raised);
    labelDisplay->setLineWidth(2);
    labelDisplay->setFixedHeight(50);

    QLabel* labelText{ new QLabel{"&Text:"} };
    QLineEdit* lineEditText{ new QLineEdit{} };
    labelText->setBuddy(lineEditText);

    QObject::connect(lineEditText,
                     &QLineEdit::textChanged,
                     labelDisplay,
                     &QLabel::setText);

    QLabel* labelPassword{ new QLabel{"&Password:"} };
    QLineEdit* lineEditPassword{ new QLineEdit{} };
    labelPassword->setBuddy(lineEditPassword);
    lineEditPassword->setEchoMode(QLineEdit::Password);

    QObject::connect(lineEditPassword,
                     &QLineEdit::textChanged,
                     labelDisplay,
                     &QLabel::setText);

    QVBoxLayout* boxLayout{ new QVBoxLayout{} };
    boxLayout->addWidget(labelDisplay);
    boxLayout->addWidget(labelText);
    boxLayout->addWidget(lineEditText);
    boxLayout->addWidget(labelPassword);
    boxLayout->addWidget(lineEditPassword);
    widget.setLayout(boxLayout);

    widget.show();

    return app.exec();
}

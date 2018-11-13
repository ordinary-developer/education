#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLineEdit lineEdit{ "user input: " };
    lineEdit.show();
    lineEdit.resize(300, 20);

    int i{0};
    for (i = 0; i < Qt::Key_Z - Qt::Key_A + 1; ++i) {
        QChar ch{ 65 + i };
        int nKey{ Qt::Key_A + i };

        QKeyEvent keyPress{ QEvent::KeyPress, nKey, Qt::NoModifier, ch };
        QApplication::sendEvent(&lineEdit, &keyPress);

        QKeyEvent keyRelease = 
            { QEvent::KeyRelease, nKey, Qt::NoModifier, ch };
        QApplication::sendEvent(&lineEdit, &keyRelease);
    }

    return app.exec();
}

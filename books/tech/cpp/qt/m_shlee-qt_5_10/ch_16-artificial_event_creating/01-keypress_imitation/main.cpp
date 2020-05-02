#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication app{ argc, argv };
    
    QLineEdit txt{ "User input: " };
    txt.show();
    txt.resize(300, 20);
    
    for (int i{0}; i < Qt::Key_Z - Qt::Key_A + 1; ++i) {
        QChar const ch = 65 + i;
        int const nKey = Qt::Key_A + i;
        QKeyEvent keyPress(QEvent::KeyPress, nKey, Qt::NoModifier, ch);
        QApplication::sendEvent(&txt, &keyPress);
        
        QKeyEvent keyRelease(QEvent::KeyRelease, nKey, Qt::NoModifier, ch);
        QApplication::sendEvent(&txt, &keyRelease);
    }
    
    return app.exec();
}
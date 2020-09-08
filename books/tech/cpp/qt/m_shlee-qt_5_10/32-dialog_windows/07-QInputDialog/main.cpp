#include <QtWidgets>
#include <QInputDialog>
#include <QMessageBox>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLabel label{ "Hello world!" };
    label.show();

    bool ok{};
    const QString& str = QInputDialog::getText(
        0, "input", "name:", QLineEdit::Normal, "text", &ok);

    QMessageBox::information(0, "information", 
        (ok ? "ok has been pressed" : "cancel has been pressed"));
 
    return app.exec();
}

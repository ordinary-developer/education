#include <QApplication>
#include <QFont>
#include <QFontDialog>
#include <QLabel>
#include <QMessageBox>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    QLabel lbl{ "label" };
    lbl.show();
    
    bool ok{};
    QFont font = QFontDialog::getFont(&ok);
    QMessageBox::information(0, "information",
        (ok ? "ok was press" : "cancel was pressed"));

    return app.exec();
}
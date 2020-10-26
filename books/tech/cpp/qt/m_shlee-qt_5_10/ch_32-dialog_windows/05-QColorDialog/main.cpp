#include <QApplication>
#include <QLabel>
#include <QColor>
#include <QColorDialog>
#include <QMessageBox>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLabel label{ "lorem ipsum" };
    label.show();

    QColor color(QColorDialog::getColor(Qt::blue));

    QMessageBox::information(0, "information", (color.isValid() ? "ok" : "cancel"));

    return app.exec();
}
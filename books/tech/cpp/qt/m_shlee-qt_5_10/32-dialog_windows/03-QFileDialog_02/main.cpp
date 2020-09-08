#include <QObject>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };


    QString const& str = QFileDialog::getExistingDirectory(
        nullptr, "Directory Dialog", "");
    
    if (not str.isEmpty())
        QMessageBox::information(0, "information", "selected directory is " + str);

    QLabel label{"Hello world"};
    label.show();

    return app.exec();
}

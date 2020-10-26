#include <QApplication>
#include <QLabel>
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    QLabel label{ "lorem ipsum" };
    label.show();
    
    QPrinter printer{};
    QPrintDialog *pPrintDlg{ new QPrintDialog{&printer} };
    if (QDialog::Accepted == pPrintDlg->exec()) {
        QMessageBox::information(0, "information", "the print btn was pressed"); 
    }
    delete pPrintDlg;

    return app.exec();
}
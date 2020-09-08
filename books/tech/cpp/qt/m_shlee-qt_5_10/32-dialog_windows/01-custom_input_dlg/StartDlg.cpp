#include "StartDlg.hpp"
#include "InputDlg.hpp"

#include <QMessageBox>
#include <QDialog>


StartDlg::StartDlg(QWidget* pWgt /* = nullptr */) : QPushButton("press me", pWgt) {
    QObject::connect(this, &QPushButton::clicked, this, &StartDlg::slotButtonClicked);
}

void StartDlg::slotButtonClicked() {
    InputDlg *pInputDlg{ new InputDlg{} };
    if (QDialog::Accepted == pInputDlg->exec())
        QMessageBox::information(
            0,
            "information",
            "first name: "
                + pInputDlg->firstName()
                + "\nlast name: "
                + pInputDlg->lastName());
    delete pInputDlg;
}

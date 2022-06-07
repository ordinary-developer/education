#pragma once

#include <QDialog>
#include <QString>

class QLineEdit;


class InputDlg : public QDialog {
    Q_OBJECT

    public:
        InputDlg(QWidget* pWgt = nullptr);

        QString firstName() const;
        QString lastName() const;

    private:
        QLineEdit *pTxtFirstName_;
        QLineEdit *pTxtLastName_;
};

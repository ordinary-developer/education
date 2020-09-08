#include "InputDlg.hpp"

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>


InputDlg::InputDlg(QWidget* pWgt /* = nullptr */)
    : QDialog(pWgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    pTxtFirstName_ = new QLineEdit{};
    pTxtLastName_  = new QLineEdit{};
    
    QLabel *pLblFirstName{ new QLabel{"&first name"} };
    QLabel *pLblLastName{ new QLabel{"&last name"} };
    pLblFirstName->setBuddy(pTxtFirstName_);
    pLblLastName->setBuddy(pTxtLastName_);
    
    QPushButton *pCmdOk{ new QPushButton{"&ok"} };
    QPushButton *pCmdCancel{ new QPushButton{"&cancel"} };
    
    QObject::connect(pCmdOk, &QPushButton::clicked,
        this, &QDialog::accept);
    QObject::connect(pCmdCancel, &QPushButton::clicked,
        this, &QDialog::reject);

    QGridLayout *pTopLayout{ new QGridLayout{} };
    pTopLayout->addWidget(pLblFirstName, 0, 0);
    pTopLayout->addWidget(pLblLastName, 1, 0);
    pTopLayout->addWidget(pTxtFirstName_, 0, 1);
    pTopLayout->addWidget(pTxtLastName_, 1, 1);
    pTopLayout->addWidget(pCmdOk, 2, 0);
    pTopLayout->addWidget(pCmdCancel, 2, 1);
    setLayout(pTopLayout);
}

QString InputDlg::firstName() const { return pTxtFirstName_->text(); }
QString InputDlg::lastName() const { return pTxtLastName_->text(); }

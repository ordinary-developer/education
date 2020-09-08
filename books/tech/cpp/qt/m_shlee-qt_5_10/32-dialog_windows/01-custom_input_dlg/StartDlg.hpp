#pragma once

#include <QPushButton>


class StartDlg : public QPushButton {
    Q_OBJECT
    public:
        StartDlg(QWidget* pWgt = nullptr); 

    public slots:
        void slotButtonClicked();
};
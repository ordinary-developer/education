#pragma once

#include <QGroupBox>

class QCheckBox;
class QRadioButton;


class Buttons : public QGroupBox {
    Q_OBJECT

    public:
        Buttons(QWidget* parentWidget = 0);

    public slots:
        void slotButtonClicked();
        
    private:
        QCheckBox* m_checkBox;
        QRadioButton* m_redRadioButton;
        QRadioButton* m_greenRadioButton;
        QRadioButton* m_blueRadioButton;
};

#pragma once

#include <QWidget>
#include <QSettings>

class QComboBox;
class QCheckBox;
class QTextEdit;
class QLabel;


class MyPrgWgt final : public QWidget {
    Q_OBJECT
    
    public:
        MyPrgWgt(QWidget *pParWgt = nullptr);
        virtual ~MyPrgWgt();
        
        void readStgs();
        void writeStgs();
        
    public slots:
        void slotCheckBoxClicked();
        void slotComboBoxActivated(int);
        
    private:
        QComboBox *pComboBox_;
        QCheckBox *pCheckBox_;
        QTextEdit *pTextEdit_;
        QLabel    *pLabel_;
        
        QSettings stgs_;
        int counter_;
};

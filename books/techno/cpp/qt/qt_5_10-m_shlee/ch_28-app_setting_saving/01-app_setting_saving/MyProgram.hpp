#pragma once

#include <QWidget>
#include <QSettings>

class QComboBox;
class QCheckBox;
class QTextEdit;
class QLabel;

class MyProgram : public QWidget {
    Q_OBJECT

    public:
        MyProgram(QWidget* parentWgt = nullptr);
        virtual ~MyProgram() final override;

        void readSettings();
        void writeSettings();

    public slots:
        void slotCheckBoxClicked();
        void slotComboBoxActivated(int);

    private:
        QSettings settings_;
        QComboBox* pComboBox_;
        QCheckBox* pCheckBox_;
        QTextEdit* pTextEdit_;
        QLabel* pLabel_;
        
        int counter_;
};

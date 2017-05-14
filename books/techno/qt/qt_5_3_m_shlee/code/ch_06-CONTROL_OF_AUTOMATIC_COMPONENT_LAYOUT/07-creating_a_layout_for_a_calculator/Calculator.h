#pragma once

#include <QWidget>
#include <QStack>

class QLCDNumber;
class QPushButton;


class Calculator : public QWidget {
    Q_OBJECT
    public:
        Calculator(QWidget* pWidget = nullptr);    
        
    public slots:
        void slotButtonClicked();

    private:
        QPushButton* createButton(QString const& buttonName);
        void calculate();

        QLCDNumber* m_pLCD;
        QStack<QString> m_stack;
        QString m_stringDisplay;
};

#include "Calculator.h"

#include <QtWidgets>


Calculator::Calculator(QWidget* pWidget) 
    : QWidget(pWidget), m_pLCD{}, m_stack{}, m_stringDisplay{} 
{
    m_pLCD = new QLCDNumber(12);
    m_pLCD->setSegmentStyle(QLCDNumber::Flat);
    m_pLCD->setMinimumSize(150, 50);

    QChar buttons[4][4] = { {'7', '8', '9', '/'},
                            {'4', '5', '6', '*'},
                            {'1', '2', '3', '-'},
                            {'0', '.', '=', '+'} };

    QGridLayout* topLayout{ new QGridLayout{} };
    topLayout->addWidget(m_pLCD, 0, 0, 1, 4);
    topLayout->addWidget(createButton("CE"), 1, 3);

    for (int i{0}; i < 4; ++i)
        for (int j{0}; j < 4; ++j)
            topLayout->addWidget(createButton(buttons[i][j]),
                                 i + 2,
                                 j);

    setLayout(topLayout);
}

QPushButton* Calculator::createButton(QString const& buttonName) {
    QPushButton* command{ new QPushButton(buttonName) };
    command->setMinimumSize(40, 40);
    connect(command, &QPushButton::clicked,
            this, &Calculator::slotButtonClicked);
    return command;
}

void Calculator::calculate() {
    double dOperand2{ m_stack.pop().toDouble() };
    QString strOperation{ m_stack.pop() };
    double dOperand1{ m_stack.pop().toDouble() };
    double dResult{0};

    if ("+" == strOperation)
        dResult = dOperand1 + dOperand2;
    if ("-" == strOperation)
        dResult = dOperand1 - dOperand2;
    if ("*" == strOperation)
        dResult = dOperand1 * dOperand2;
    if ("/" == strOperation)
        dResult = dOperand1 / dOperand2;

    m_pLCD->display(dResult);
}

void Calculator::slotButtonClicked() {
    QString str{ ((QPushButton*)sender())->text() };

    if ("CE" == str) {
        m_stack.clear();
        m_stringDisplay = "";
        m_pLCD->display("0");
        return;
    }
    if (str.contains(QRegExp("[0-9]"))) {
        m_stringDisplay += str;
        m_pLCD->display(m_stringDisplay.toDouble());
    }
    else if("." == str) {
        m_stringDisplay += str;
        m_pLCD->display(m_stringDisplay);
    }
    else {
        if (m_stack.count() >= 2) {
            m_stack.push(QString().setNum(m_pLCD->value()));
            calculate();
            m_stack.clear();
            m_stack.push(QString().setNum(m_pLCD->value()));
            if ("=" != str)
                m_stack.push(str);
        }
        else {
            m_stack.push(QString().setNum(m_pLCD->value()));
            m_stack.push(str);
            m_stringDisplay = "";
            m_pLCD->display("0");
        }
    }
}

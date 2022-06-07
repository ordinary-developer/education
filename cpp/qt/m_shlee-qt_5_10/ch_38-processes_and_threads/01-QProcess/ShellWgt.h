#pragma once

#include <QtWidgets>

class ShellWgt : public QWidget {
Q_OBJECT

private:
    QProcess* m_process;
    QLineEdit* m_ptxtCommand;
    QTextEdit* m_ptxtDisplay;
    
public:
    ShellWgt(QWidget* parentWgt = nullptr) : QWidget{parentWgt} {
        m_process = new QProcess{this};
        m_ptxtDisplay = new QTextEdit{};
        
        QLabel* plbl = new QLabel{"&Command:"};
#ifdef Q_OS_WIN
        QString strCommand = "dir";
#else
        QSTring strCommand = "ls";
#endif
        
        m_ptxtCommand = new QLineEdit{strCommand};
        plbl->setBuddy(m_ptxtCommand);
        
        QPushButton* pcmd = new QPushButton{"&Enter"};
        
        QObject::connect(m_process, &QProcess::readyReadStandardOutput,
            this, &ShellWgt::slotDataOnStdout);
        QObject::connect(m_ptxtCommand, &QLineEdit::returnPressed,
            this, &ShellWgt::slotReturnPressed);
        QObject::connect(pcmd, &QPushButton::clicked,
            this, &ShellWgt::slotReturnPressed);
        
        QBoxLayout* hBoxLayout = new QHBoxLayout{};
        hBoxLayout->addWidget(plbl);
        hBoxLayout->addWidget(m_ptxtCommand);
        hBoxLayout->addWidget(pcmd);
        
        QVBoxLayout* vBoxLayout = new QVBoxLayout{};
        vBoxLayout->addWidget(m_ptxtDisplay);
        vBoxLayout->addLayout(hBoxLayout);
        
        setLayout(vBoxLayout);
    }
    
public slots:
    void slotDataOnStdout() {
        m_ptxtDisplay->append(m_process->readAllStandardOutput());
    }
    
    void slotReturnPressed() {
        QString strCommand = "";
#ifdef Q_OS_WIN
        strCommand = "cmd /C ";
#endif
        strCommand += m_ptxtCommand->text();
        m_process->start(strCommand);
    }
};

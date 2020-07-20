#pragma once

#include <QString>
#include <QStringList>
#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>


class HelpBrowser : public QWidget {
    Q_OBJECT

    public:
        HelpBrowser(
            const QString& strPath,
            const QString& strFileName,
            QWidget* pWgt = nullptr
        ) : QWidget{pWgt}
        {
            QPushButton* pBackBtn = new QPushButton{ "<<" };
            QPushButton* pHomeBtn = new QPushButton{ "Home" };
            QPushButton* pForwardBtn = new QPushButton{ ">>" };
            QTextBrowser* pTxtBrowser = new QTextBrowser{};

            QObject::connect(pBackBtn, &QPushButton::clicked,
                pTxtBrowser, &QTextBrowser::backward);

            QObject::connect(pHomeBtn, &QPushButton::clicked,
                pTxtBrowser, &QTextBrowser::home);

            QObject::connect(pForwardBtn, &QPushButton::clicked,
                pTxtBrowser, &QTextBrowser::forward);
    
            QObject::connect(pTxtBrowser, &QTextBrowser::backwardAvailable,
                pBackBtn, &QPushButton::setEnabled);

            QObject::connect(pTxtBrowser, &QTextBrowser::forwardAvailable,
                pForwardBtn, &QPushButton::setEnabled);
                
            pTxtBrowser->setSearchPaths(QStringList() << strPath);
            pTxtBrowser->setSource(QString{ strFileName });
            
            // layout
            QVBoxLayout* pVBoxLayout = new QVBoxLayout{};
            QHBoxLayout* pHBoxLayout = new QHBoxLayout{};
            pHBoxLayout->addWidget(pBackBtn);
            pHBoxLayout->addWidget(pHomeBtn);
            pHBoxLayout->addWidget(pForwardBtn);
            pVBoxLayout->addLayout(pHBoxLayout);
            pVBoxLayout->addWidget(pTxtBrowser);
            setLayout(pVBoxLayout);
        }
};

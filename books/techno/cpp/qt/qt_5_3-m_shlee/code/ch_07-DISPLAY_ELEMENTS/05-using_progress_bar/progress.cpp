#include "progress.hpp"

#include <QtWidgets>


Progress::Progress(QWidget* parentWidget)
    : QWidget{parentWidget}, m_step{0} 
{
    m_progressBar = new QProgressBar{};
    m_progressBar->setRange(0, 5);
    m_progressBar->setMinimumWidth(200);
    m_progressBar->setAlignment(Qt::AlignCenter);

    QPushButton* stepButton{ new QPushButton("&Step") };
    QPushButton* resetButton{ new QPushButton("&Reset") };

    QObject::connect(stepButton, &QPushButton::clicked,
                     this, &Progress::slotStep);
    QObject::connect(resetButton, &QPushButton::clicked,
                     this, &Progress::slotReset);

    QHBoxLayout* layout{ new QHBoxLayout{} };
    layout->addWidget(m_progressBar);
    layout->addWidget(stepButton);
    layout->addWidget(resetButton);

    setLayout(layout);
}

void Progress::slotStep()
{
    m_progressBar->setValue(++m_step);
}

void Progress::slotReset()
{
    m_step = 0;
    m_progressBar->reset();
}


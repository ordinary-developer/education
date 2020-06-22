#include "buttons.hpp"

#include <QtWidgets>

Buttons::Buttons(QWidget* parentWidget) 
    : QGroupBox{ "QGroupBox", parentWidget } 
{
    resize(100, 150);
    setCheckable(true);
    setChecked(true);

    m_redRadioButton = new QRadioButton{"&Red"};
    m_greenRadioButton = new QRadioButton{"&Green"};
    m_blueRadioButton = new QRadioButton{"&Blue"};
    m_greenRadioButton->setChecked(true);
    connect(m_redRadioButton, &QRadioButton::clicked,
            this, &Buttons::slotButtonClicked);
    connect(m_greenRadioButton, &QRadioButton::clicked,
            this, &Buttons::slotButtonClicked);
    connect(m_blueRadioButton, &QRadioButton::clicked,
            this, &Buttons::slotButtonClicked);

    m_checkBox = new QCheckBox{"&Light"};
    m_checkBox->setChecked(true);
    connect(m_checkBox, &QCheckBox::clicked, 
            this, &Buttons::slotButtonClicked);

    QPushButton* button{ new QPushButton{"&Exit"} };
    connect(button, &QPushButton::clicked,
            qApp, &QApplication::quit);

    QVBoxLayout* boxLayout{ new QVBoxLayout{} };
    boxLayout->addWidget(m_redRadioButton);
    boxLayout->addWidget(m_greenRadioButton);
    boxLayout->addWidget(m_blueRadioButton);
    boxLayout->addWidget(m_checkBox);
    boxLayout->addWidget(button);
    setLayout(boxLayout);

    slotButtonClicked();
}

void Buttons::slotButtonClicked()
{
    QPalette palette{};

    int light{ m_checkBox->isChecked() ? 150 : 80 };
    if (m_redRadioButton->isChecked())
        palette.setColor(backgroundRole(), QColor(Qt::red).light(light));
    else if(m_greenRadioButton->isChecked())
        palette.setColor(backgroundRole(), QColor(Qt::green).light(light));
    else
        palette.setColor(backgroundRole(), QColor(Qt::blue).light(light));

    setPalette(palette);
}

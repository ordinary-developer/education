#include "MyProgram.hpp"

#include <QtWidgets>

MyProgram::MyProgram(QWidget* parentWgt /*= nullptr*/)
    : QWidget{ parentWgt },
    settings_{ "BHV", "MyProgram" },
    pComboBox_{ new QComboBox{} },
    pCheckBox_{ new QCheckBox{ "Disable edit" } },
    pTextEdit_{ new QTextEdit{} },
    pLabel_{ new QLabel{} },
    counter_{ 1 }
{
    pComboBox_->addItem("Classic");
    pComboBox_->addItem("Borland");

    connect(pCheckBox_, &QCheckBox::clicked, 
        this, &MyProgram::slotCheckBoxClicked);
    connect(
        pComboBox_, 
        static_cast<void (QComboBox::*)(int)>
            (&QComboBox::activated),
        this, 
        static_cast<void (MyProgram::*)(int)>
            (&MyProgram::slotComboBoxActivated));

    readSettings();

    QVBoxLayout* pVboxLayout = { new QVBoxLayout{} };
    QHBoxLayout* pHboxLayout = { new QHBoxLayout{} };

    pVboxLayout->setContentsMargins(5, 5, 5, 5);
    pHboxLayout->setSpacing(15);
    pVboxLayout->setSpacing(15);
    pVboxLayout->addWidget(pLabel_);
    pVboxLayout->addWidget(pTextEdit_);
    pHboxLayout->addWidget(pComboBox_);
    pHboxLayout->addWidget(pCheckBox_);

    pVboxLayout->addLayout(pHboxLayout);

    setLayout(pVboxLayout);
}

MyProgram::~MyProgram() { writeSettings(); }

void MyProgram::readSettings() {
    settings_.beginGroup("/settings");

    QString textValue = { settings_.value("/text", "").toString() };
    int widthValue = { settings_.value("/width", width()).toInt() };
    int heightValue = { settings_.value("/height", height()).toInt() };
    int comboItemValue = { settings_.value("/highlight", 0).toInt() };
    bool toEditValue = { settings_.value("/to_edit", false).toBool() };

    counter_ = settings_.value("/counter", 1).toInt();

    QString str = QString{}.setNum(counter_);
    ++counter_;
    pLabel_->setText("this program has been started " + str + " times");

    pTextEdit_->setPlainText(textValue);

    resize(widthValue, heightValue);

    pCheckBox_->setChecked(toEditValue);
    slotCheckBoxClicked();

    pComboBox_->setCurrentIndex(comboItemValue);
    slotComboBoxActivated(comboItemValue);

    settings_.endGroup();
}

void MyProgram::writeSettings() {
    settings_.beginGroup("/settings");
    settings_.setValue("/counter", counter_);
    settings_.setValue("/text", pTextEdit_->toPlainText());
    settings_.setValue("/width", width());
    settings_.setValue("/height", height());
    settings_.setValue("/highlight", pComboBox_->currentIndex());
    settings_.setValue("/to_edit", pCheckBox_->isChecked());
    settings_.endGroup();
}

void MyProgram::slotCheckBoxClicked() {
    pTextEdit_->setEnabled(not pCheckBox_->isChecked());
}

void MyProgram::slotComboBoxActivated(int n) {
    QPalette palette = pTextEdit_->palette();

    palette.setColor(
        QPalette::Active, QPalette::Base, n ? Qt::darkBlue : Qt::white);
    palette.setColor(
        QPalette::Active, QPalette::Text, n ? Qt::yellow : Qt::black);

    pTextEdit_->setPalette(palette);
}

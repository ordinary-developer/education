#include "MyPrgWgt.hpp"

#include <QComboBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>


// ctor/dtor
MyPrgWgt::MyPrgWgt(QWidget *pParWgt /* = nullptr */)
    : QWidget(pParWgt),
    pComboBox_{ new QComboBox{} }, pCheckBox_{ new QCheckBox{ "disable edit" } },
    pTextEdit_{ new QTextEdit{} }, pLabel_{ new QLabel{} },
    stgs_{ "organization", "programm" }, counter_{0}
{
    pComboBox_->addItem("classic");
    pComboBox_->addItem("borland");
    
    //connect(pCheckBox_, SIGNAL(clicked()), SLOT(slotCheckBoxClicked()));
    //connect(pComboBox_, SIGNAL(activated(int)), SLOT(slotComboBoxActivated(int)));
    
    QObject::connect(pCheckBox_, &QCheckBox::clicked,
        this, &MyPrgWgt::slotCheckBoxClicked);
    QObject::connect(pComboBox_, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated),
        this, &MyPrgWgt::slotComboBoxActivated);
    
    readStgs();
    
    QHBoxLayout *pHbxLayout = new QHBoxLayout{};
    pHbxLayout->setSpacing(15);
    pHbxLayout->addWidget(pComboBox_);
    pHbxLayout->addWidget(pCheckBox_);
    
    QVBoxLayout *pVbxLayout = new QVBoxLayout{};
    pVbxLayout->setSpacing(15);
    pVbxLayout->setContentsMargins(5, 5, 5, 5);
    pVbxLayout->addWidget(pLabel_);
    pVbxLayout->addWidget(pTextEdit_);
    
    pVbxLayout->addLayout(pHbxLayout);
    
    setLayout(pVbxLayout);
}

MyPrgWgt::~MyPrgWgt() { writeStgs(); }


// interface
void MyPrgWgt::readStgs() {
    stgs_.beginGroup("/Settings");
    
    QString const & txt = stgs_.value("/text", "").toString();
    int const widthVal  = stgs_.value("/width", width()).toInt();
    int const heightVal = stgs_.value("/height", height()).toInt();
    int const comboItem = stgs_.value("/highlight", 0).toInt();
    bool const edit = stgs_.value("/edit", false).toBool();
    
    counter_ = stgs_.value("/counter", 1).toInt();
    
    QString const & str = QString{}.setNum(counter_++);
    pLabel_->setText(
        QString{ "this program has been started %0 times" }
            .arg(str));
            
    pTextEdit_->setPlainText(txt);
    
    resize(widthVal, heightVal);
    
    pCheckBox_->setChecked(edit);
    slotCheckBoxClicked();
    
    pComboBox_->setCurrentIndex(comboItem);
    slotComboBoxActivated(comboItem);
    
    stgs_.endGroup();
}

void MyPrgWgt::writeStgs()
{
    stgs_.beginGroup("/Settings");
    stgs_.setValue("/counter", counter_);
    stgs_.setValue("/text", pTextEdit_->toPlainText());
    stgs_.setValue("/width", width());
    stgs_.setValue("/height", height());
    stgs_.setValue("/highlight", pComboBox_->currentIndex());
    stgs_.setValue("/edit", pCheckBox_->isChecked());
    stgs_.endGroup();
}


// slots
void MyPrgWgt::slotCheckBoxClicked()
{
    pTextEdit_->setEnabled(not pCheckBox_->isChecked());
}

void MyPrgWgt::slotComboBoxActivated(int n)
{
    QPalette pal = pTextEdit_->palette();
    pal.setColor(QPalette::Active, QPalette::Base, n ? Qt::darkBlue : Qt::white);
    pal.setColor(QPalette::Active, QPalette::Text, n ? Qt::yellow : Qt::black);
    pTextEdit_->setPalette(pal);
}

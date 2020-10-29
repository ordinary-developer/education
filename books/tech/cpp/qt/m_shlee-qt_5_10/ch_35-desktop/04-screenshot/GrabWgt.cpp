#include "GrabWgt.hpp"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include <QPixmap>


// ctor
GrabWgt::GrabWgt(QWidget* parentWgt /* = nulptr */) : QWidget{ parentWgt } {
    resize(640, 480);

    label_ = new QLabel{};

    QPushButton* btn = new QPushButton{ "Capture Screen" };
    QObject::connect(btn, &QPushButton::clicked, 
        this, &GrabWgt::slotGrabScreen);

    QVBoxLayout* layout = new QVBoxLayout{};
    layout->addWidget(btn);
    layout->addWidget(label_);
    setLayout(layout);
}


// public slots
void GrabWgt::slotGrabScreen() {
    QDesktopWidget* pDesktop = QApplication::desktop();
    QPixmap pic = QPixmap::grabWindow(pDesktop->screen()->winId());

    label_->setPixmap(pic.scaled(label_->size()));
}

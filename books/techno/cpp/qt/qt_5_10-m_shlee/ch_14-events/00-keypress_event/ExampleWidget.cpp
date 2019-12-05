#include "ExampleWidget.hpp"

#include <QDebug>
#include <QKeyEvent>


ExampleWidget::ExampleWidget(QWidget * pParWgt /* = nullptr */)
    : QLabel{ pParWgt } {}
    
void ExampleWidget::keyPressEvent(QKeyEvent* pEvent) {
    switch (pEvent->key()) {
        case Qt::Key_Z:
            if (pEvent->modifiers() & Qt::ShiftModifier) {
                qDebug("z key was pressed with shift");
            }
            else {
                qDebug("z key was pressed without shift");
            }
            
        default:
            QWidget::keyPressEvent(pEvent);
    }
}


#include "ExampleWidget.hpp"

ExampleWidget::ExampleWidget(QWidget* pParWgt /* = nullptr */)
    : QLabel{ pParWgt }
{
    setAlignment(Qt::AlignCenter);
}

bool ExampleWidget::event(QEvent* pEvent) {
    if (QEvent::KeyPress == pEvent->type()) {
        qDebug() << "a key was pressed";
        QKeyEvent* pKeyEvent = static_cast<QKeyEvent*>(pEvent);
        if (Qt::Key_Tab == pKeyEvent->key()) {
            qDebug() << "the tab key was pressed";
            return true;
        }
    }
    
    if (QEvent::Hide == pEvent->type()) {
        qDebug() << "hide event was raised";
        return true;
    }
    
    return true;
}
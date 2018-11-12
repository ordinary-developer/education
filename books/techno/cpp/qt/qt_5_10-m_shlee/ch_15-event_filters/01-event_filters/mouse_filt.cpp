#include "mouse_filt.hpp"

#include <QtWidgets>

MouseFilter::MouseFilter(QObject* parObj /* = nullptr */)
    : QObject(parObj)
{}


bool MouseFilter::eventFilter(QObject* parentObj, QEvent* pEvent) {
    if (QEvent::MouseButtonPress == pEvent->type()) {
        if (Qt::LeftButton == 
                static_cast<QMouseEvent*>(pEvent)->button())
        {
            QString strClassName{ parentObj->metaObject()->className() };
            QMessageBox::information(0, "class name", strClassName);
            return true;
        }
    }
    
    return false;
}


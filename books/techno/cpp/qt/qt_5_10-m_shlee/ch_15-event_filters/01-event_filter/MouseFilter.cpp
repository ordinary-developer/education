#include "MouseFilter.hpp"

#include <QEvent>
#include <QMouseEvent>
#include <QMessageBox>

MouseFilter::MouseFilter(QObject *pParObj /* = nullptr */) : QObject(pParObj) {}

bool MouseFilter::eventFilter(QObject *pObj, QEvent *pEvent) {
    if (QEvent::MouseButtonPress == pEvent->type()) {
        if (Qt::LeftButton == static_cast<QMouseEvent*>(pEvent)->button()) {
            QString const& strClassName = pObj->metaObject()->className();
            QMessageBox::information(0, "Class Name", strClassName);
            return true;
        }
    }
    
    return false;
}
    

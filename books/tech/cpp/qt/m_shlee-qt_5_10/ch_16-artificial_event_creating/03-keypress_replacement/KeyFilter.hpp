#pragma once

#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QApplication>


class KeyFilter : public QObject {
    public:
        KeyFilter(QObject *pObj = nullptr) : QObject{ pObj } {}
        
    protected:
        bool eventFilter(QObject *pObj, QEvent *pEvent) {
            if (QKeyEvent::KeyPress != pEvent->type())
                return false;
            
            if (Qt::Key_Z != static_cast<QKeyEvent*>(pEvent)->key())
                return false;
            
            QKeyEvent keyEvent{ QEvent::KeyPress,
                Qt::Key_A, Qt::NoModifier, "A" };
            QApplication::sendEvent(pObj, &keyEvent);
            
            return true;
        }
};

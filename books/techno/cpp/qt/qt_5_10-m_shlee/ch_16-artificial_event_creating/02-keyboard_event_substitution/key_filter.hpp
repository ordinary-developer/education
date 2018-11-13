#pragma once

#include <QtWidgets>

class KeyFilter : public QObject {
    public:
        KeyFilter(QObject* parentObj = nullptr)
            : QObject(parentObj)
        {}

    protected:
        bool eventFilter(QObject* parentObj, QEvent* pEvent) {
            if (QEvent::KeyPress == pEvent->type()) {
                if (Qt::Key_Z == static_cast<QKeyEvent*>(pEvent)->key()) {
                    QKeyEvent keyEvent = {
                        QEvent::KeyPress, Qt::Key_A, Qt::NoModifier, "A" };
                    QApplication::sendEvent(parentObj, &keyEvent);
                    return true;
                }
            }
            return false;
        }
};



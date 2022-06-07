#pragma once

#include <QObject>

class MouseFilter final : public QObject {
    public:
        MouseFilter(QObject *pParObj = nullptr);
        
    protected:
        virtual bool eventFilter(QObject *pObj, QEvent *pEvent) final override;
};
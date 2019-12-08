#pragma once

#include <QtWidgets>

class MouseWheelObserver : public QLabel {
    public:
        MouseWheelObserver(QWidget* pWgt = nullptr);
        
    protected:
        virtual void wheelEvent(QWheelEvent* pEvent) final override;
};

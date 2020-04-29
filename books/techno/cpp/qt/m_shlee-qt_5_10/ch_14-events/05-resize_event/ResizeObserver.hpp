#pragma once

#include <QtWidgets>

class ResizeObserver : public QLabel {
    public:
        ResizeObserver(QWidget* pParWgt = nullptr);
    
    protected:
        virtual void resizeEvent(QResizeEvent* pEvent) final override;
};

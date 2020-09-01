#pragma once

#include <QWidget>
#include <QTouchEvent>

class MultiTouchWidget : public QWidget {
    public:
        MultiTouchWidget(QWidget * pParWgt = nullptr);
        
    protected:
        virtual bool event(QEvent*) final override;
        virtual void paintEvent(QPaintEvent*) final override;
        
    private:
        QList<QColor> colors_;
        QList<QTouchEvent::TouchPoint> touchPoints_;
};

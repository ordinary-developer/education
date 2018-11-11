#pragma once

#include <QWidget>
#include <QTouchEvent>

class MultitouchWidget : public QWidget {
    public:
        MultitouchWidget(QWidget * parentWidget = nullptr);

    protected:
        virtual void paintEvent(QPaintEvent*) final override;
        virtual bool event(QEvent*) final override;

    private:
        QList<QColor> colorLst_;
        QList<QTouchEvent::TouchPoint> touchPtLst_;
};


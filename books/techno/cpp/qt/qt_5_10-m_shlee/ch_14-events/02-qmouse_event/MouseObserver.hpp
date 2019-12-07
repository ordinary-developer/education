#pragma once

#include <QtWidgets>

class MouseObserver : public QLabel {
    public:
        MouseObserver(QWidget * pWgt = nullptr);
        
    protected:
        virtual void mousePressEvent(QMouseEvent* pEvent) final override;
        virtual void mouseReleaseEvent(QMouseEvent* pEvent) final override;
        virtual void mouseMoveEvent(QMouseEvent* pEvent) final override;
        
    private:
        void dump_event(const QMouseEvent* const pEvent, const QString & strMsg);
        QString modifier_info(const QMouseEvent * const pEvent);
        QString button_info(const QMouseEvent* const pEvent);
};

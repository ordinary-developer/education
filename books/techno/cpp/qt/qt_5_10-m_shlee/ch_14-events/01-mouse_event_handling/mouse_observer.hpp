#pragma once

#include <QtWidgets>

class MouseObserver : public QLabel {
    public:
        MouseObserver(QWidget* parentWidget = nullptr);

    protected:
        virtual void mousePressEvent(QMouseEvent* pe) final override;
        virtual void mouseReleaseEvent(QMouseEvent* pe) final override;
        virtual void mouseMoveEvent(QMouseEvent* pe) final override;

    private:
        void dumpEvent(QMouseEvent* pe, QString const& strMsg);
        QString buttonsInfo(QMouseEvent* pe);
        QString modifiersInfo(QMouseEvent* pe);
};


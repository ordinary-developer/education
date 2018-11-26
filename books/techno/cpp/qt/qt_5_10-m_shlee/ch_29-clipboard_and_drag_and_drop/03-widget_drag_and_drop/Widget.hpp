#pragma once

#include <QPoint>
#include <QLabel>


class Widget : public QLabel {
    Q_OBJECT
    public:
        Widget(QWidget* pParentWgt = nullptr);

    protected:
        virtual void mousePressEvent(QMouseEvent*) final override;
        virtual void mouseMoveEvent(QMouseEvent*) final override;
        virtual void dragEnterEvent(QDragEnterEvent*) final override;
        virtual void dropEvent(QDropEvent*) final override;

    private:
        void startDrag();

        QPoint ptDragPos_;
};

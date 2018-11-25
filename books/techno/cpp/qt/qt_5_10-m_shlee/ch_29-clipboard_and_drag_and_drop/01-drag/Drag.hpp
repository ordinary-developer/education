#pragma once

#include <QtWidgets>

class Drag : public QLabel { 
    Q_OBJECT
    public:
        Drag(QWidget* parentWgt = nullptr)
            : QLabel{ "this is a draggalbe text", parentWgt } {}

    protected:
        virtual void mousePressEvent(QMouseEvent* pe) final override {
            if (Qt::LeftButton == pe->button()) 
                ptDragPos_ = pe->pos();
            QWidget::mousePressEvent(pe);
        }

        virtual void mouseMoveEvent(QMouseEvent* pe) final override {
            if (pe->buttons() & Qt::LeftButton) {
                int dist = (pe->pos() - ptDragPos_).manhattanLength();
                if (dist > QApplication::startDragDistance())
                    startDrag();
            }
            QWidget::mouseMoveEvent(pe);
        }

    private:
        void startDrag() {
            QMimeData* pMimeData{ new QMimeData{} };
            pMimeData->setText(text());

            QDrag* pDrag{ new QDrag{this} };
            pDrag->setMimeData(pMimeData);
            pDrag->setPixmap(QPixmap(":/img.jpg"));
            pDrag->exec(Qt::MoveAction);
        }
        QPoint ptDragPos_;
};


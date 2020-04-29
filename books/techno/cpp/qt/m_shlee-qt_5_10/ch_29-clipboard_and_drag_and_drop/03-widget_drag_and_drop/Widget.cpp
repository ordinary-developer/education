#include <QtWidgets>

#include "Widget.hpp"
#include "WidgetDrag.hpp"


Widget::Widget(QWidget* pParentWgt /* = nullptr*/) : QLabel(pParentWgt)
{
    setAcceptDrops(true);
}

void Widget::mousePressEvent(QMouseEvent* pe) {
    if (Qt::LeftButton == pe->button())
        ptDragPos_ = pe->pos();
    QWidget::mousePressEvent(pe);
}

void Widget::mouseMoveEvent(QMouseEvent* pe) {
    if (pe->buttons() & Qt::LeftButton) {
        int dist = (pe->pos() - ptDragPos_).manhattanLength();
        if (dist > QApplication::startDragDistance()) {
            startDrag();
        }
    }
    QWidget::mouseMoveEvent(pe);
}

void Widget::dragEnterEvent(QDragEnterEvent* pe) {
    if (pe->mimeData()->hasFormat(WidgetMimeData::mimeType()))
        pe->acceptProposedAction();
}

void Widget::dropEvent(QDropEvent* pe) {
    const WidgetMimeData* pMimeData =
        dynamic_cast<const WidgetMimeData*>(pe->mimeData());
    if (pMimeData) {
        QWidget* pWgt = pMimeData->widget();
        QString str{ "Widget is dropped\n ObjectName:%1" };
        setText(str.arg(pWgt->objectName()));
    }
}
void Widget::startDrag() {
    WidgetDrag* pDrag = new WidgetDrag{this};    
    pDrag->setWidget(this);
    pDrag->exec(Qt::CopyAction);
}

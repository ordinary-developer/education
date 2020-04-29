#include "MultiTouchWidget.hpp"

#include <QPainter>


MultiTouchWidget::MultiTouchWidget(QWidget * pParWgt /* = nullptr */)
    : QWidget{ pParWgt }
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    
    colors_ << Qt::cyan << Qt::green << Qt::blue << Qt::black
        << Qt::red << Qt::magenta << Qt::darkYellow
        << Qt::gray << Qt::darkCyan << Qt::darkBlue; 
}

bool MultiTouchWidget::event(QEvent* pEvent) {
    switch (pEvent->type()) {
        case QEvent::TouchBegin:
        case QEvent::TouchUpdate:
        case QEvent::TouchEnd:
        {
            QTouchEvent* pTouchEvent = static_cast<QTouchEvent*>(pEvent);
            touchPoints_ = pTouchEvent->touchPoints();
            update();
        }
        default:
            return QWidget::event(pEvent);
    }
    
    return true;
}

void MultiTouchWidget::paintEvent(QPaintEvent*) {
    QPainter painter{ this };
    painter.setRenderHint(QPainter::Antialiasing, true);
    
    int const colCount = colors_.count();
    foreach (QTouchEvent::TouchPoint touchPoint, touchPoints_) {
        switch (touchPoint.state()) {
            case Qt::TouchPointStationary:
                continue;
            default:
                QColor color{ colors_.at(touchPoint.id() % colCount) };
                painter.setPen(color);
                painter.setBrush(color);
                
                QRectF rect1{ touchPoint.pos(), QSize{ 20, 20 } };
                QRectF rect2{ touchPoint.startPos(), QSize{ 20, 20 } };
                painter.drawEllipse(rect1.translated(-10, -10));
                painter.drawEllipse(rect2.translated(-10, -10));
                
                painter.drawLine(touchPoint.pos(), touchPoint.startPos());
        }
    }
    
    
}

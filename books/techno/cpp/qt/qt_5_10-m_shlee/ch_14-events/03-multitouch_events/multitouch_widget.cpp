#include "multitouch_widget.hpp"
#include <QPainter>

MultitouchWidget::MultitouchWidget(QWidget * parentWidget /*= nullptr */)
    : QWidget(parentWidget)
{
    setAttribute(Qt::WA_AcceptTouchEvents);

    colorLst_
        << Qt::cyan << Qt::green << Qt::blue << Qt::black
        << Qt::red << Qt::magenta << Qt::darkYellow
        << Qt::gray << Qt::darkCyan << Qt::darkBlue;
}

void MultitouchWidget::paintEvent(QPaintEvent*) {
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing, true);

    int colorCount = colorLst_.count();
    foreach (QTouchEvent::TouchPoint touchPt, touchPtLst_) {
        switch (touchPt.state()) {
            case Qt::TouchPointStationary:
                continue;
            default:
                QColor color{ colorLst_.at(touchPt.id() % colorCount) };
                painter.setPen(color);
                painter.setBrush(color);

                QRectF r1{ touchPt.pos(), QSize{ 20, 20 } };
                QRectF r2{ touchPt.startPos(), QSize{ 20, 20 } };
                painter.drawEllipse(r1.translated(-10, -10));
                painter.drawEllipse(r2.translated(-10, -10));

                painter.drawLine(touchPt.pos(), touchPt.startPos());
        }
    }
}

bool MultitouchWidget::event(QEvent* pEvent) {
    switch (pEvent->type()) {
        case QEvent::TouchBegin:
        case QEvent::TouchUpdate:
        case QEvent::TouchEnd: {
            QTouchEvent* pTouchEvent = static_cast<QTouchEvent*>(pEvent);
            touchPtLst_ = pTouchEvent->touchPoints();
            update();
        }
        default:
            return QWidget::event(pEvent);
    }
    return true;
}

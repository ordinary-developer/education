#include "MouseWheelObserver.hpp"

#include <QDebug>

MouseWheelObserver::MouseWheelObserver(QWidget* pWgt /* = nullptr */)
    : QLabel(pWgt)
{
    setAlignment(Qt::AlignCenter);
    setText("demo\n");
}

void MouseWheelObserver::wheelEvent(QWheelEvent* pEvent) {
    QPoint nAngle = pEvent->angleDelta();
    QPoint nPixels = pEvent->pixelDelta();
    
    if (not nAngle.isNull()) {
        qDebug("using nAngle");
        qDebug() << QString{ "angle.x: %0, angle.y: %1" }
            .arg(QString::number(nAngle.x()), QString::number(nAngle.y()));
    }
    else if (not nPixels.isNull()) {
        qDebug("using nPixels");
    }
}

#include "ResizeObserver.hpp"

ResizeObserver::ResizeObserver(QWidget* pParWgt /* = nullptr */)
    : QLabel{ pParWgt }
{
    setAlignment(Qt::AlignCenter);
}

void ResizeObserver::resizeEvent(QResizeEvent* pEvent) {
    setText(QString("Resize") 
        + "\n width() = " + QString::number(pEvent->size().width())
        + "\n height() = " + QString::number(pEvent->size().height()));
}

#include "MouseObserver.hpp"

// ctor
MouseObserver::MouseObserver(QWidget * pWgt /* = nullptr */)
    : QLabel(pWgt)
{
    setAlignment(Qt::AlignCenter);
    setText("mouse interaction\n(press a mouse button)");
}

// override
void MouseObserver::mousePressEvent(QMouseEvent* pEvent) {
    dump_event(pEvent, "mouse pressed");
}

void MouseObserver::mouseReleaseEvent(QMouseEvent* pEvent) {
    dump_event(pEvent, "mouse released");
}

void MouseObserver::mouseMoveEvent(QMouseEvent* pEvent) {
    dump_event(pEvent, "mouse is moving");
}    

// impl
void MouseObserver::dump_event(const QMouseEvent* const pEvent, const QString & strMsg) {
    setText(strMsg
            + "\n buttons() = " + button_info(pEvent)
            + "\n x() = " + QString::number(pEvent->x())
            + "\n y() = " + QString::number(pEvent->y())
            + "\n globalX() = " + QString::number(pEvent->globalX())
            + "\n globalY() = " + QString::number(pEvent->globalY())
            + "\n modifiers() = " + modifier_info(pEvent)
            );
}

QString MouseObserver::modifier_info(const QMouseEvent * const pEvent) {
    QString modStr;
    
    if (Qt::ShiftModifier & pEvent->modifiers())
        modStr += "shif ";
    
    if (Qt::ControlModifier & pEvent->modifiers())
        modStr += "ctrl ";
    
    if (Qt::AltModifier & pEvent->modifiers())
        modStr += "alt";
    
    return modStr;
}

QString MouseObserver::button_info(const QMouseEvent* const pEvent) {
    QString butStr{};
    
    if (Qt::LeftButton & pEvent->buttons())
        butStr += "left ";
    
    if (Qt::RightButton & pEvent->buttons())
        butStr += "right ";
    
    if (Qt::MidButton & pEvent->buttons()) 
        butStr += "middle";
        
    return butStr;
}
#include "mouse_observer.hpp"

// ctor
MouseObserver::MouseObserver(QWidget* parentWidget)
    : QLabel(parentWidget)
{
    setAlignment(Qt::AlignCenter);
    setText("mouse interactions\n(press a mouse  button)");
}

// inheritance
void MouseObserver::mousePressEvent(QMouseEvent* pe) {
    dumpEvent(pe, "mouse pressed");
}

void MouseObserver::mouseReleaseEvent(QMouseEvent* pe) {
    dumpEvent(pe, "mouse release");
}

void MouseObserver::mouseMoveEvent(QMouseEvent* pe) {
    dumpEvent(pe, "mouse is moving");
}

// impl
void MouseObserver::dumpEvent(QMouseEvent* pe, QString const& strMsg) {
    setText(strMsg
            + "\n buttons()=" + buttonsInfo(pe)
            + "\n x()=" + QString::number(pe->x())
            + "\n y()=" + QString::number(pe->y())
            + "\n globalX()=" + QString::number(pe->globalX())
            + "\n globalY()=" + QString::number(pe->globalY())
            + "\n modifiers()=" + modifiersInfo(pe));
}

QString MouseObserver::buttonsInfo(QMouseEvent* pe) {
    QString strButtons{};

    if (pe->buttons() & Qt::LeftButton) {
        strButtons += "Left ";
    }
    if (pe->buttons() & Qt::RightButton) {
        strButtons += "Right ";
    }
    if (pe->buttons() & Qt::MidButton) {
        strButtons += "Middle";
    }

    return strButtons;
}

QString MouseObserver::modifiersInfo(QMouseEvent* pe) {
    QString strModifiers;

    if (pe->modifiers() & Qt::ShiftModifier) {
        strModifiers += "Shif ";
    }
    if (pe->modifiers() & Qt::ControlModifier) {
        strModifiers += "Control ";
    }
    if (pe->modifiers() & Qt::AltModifier) {
        strModifiers += "Alt";
    }

    return strModifiers;
}


#include "ExampleWidget.hpp"

#include <QApplication>
#include <QWidget>
#include <QMouseEvent>


namespace {

void local_mousePress(
    QWidget *pWgt, 
    int x, 
    int y,
    Qt::MouseButton bt = Qt::LeftButton,
    Qt::MouseButtons bts = Qt::LeftButton)
{
    if (not pWgt) 
        return;
    
    QMouseEvent *pMousePressEvent =
        new QMouseEvent(
            QEvent::MouseButtonPress,
            QPoint(x, y),
            bt,
            bts, 
            Qt::NoModifier);
            
    QApplication::postEvent(pWgt, pMousePressEvent);
}
} // unonymous


int main(int argc, char **argv) {
    QApplication app{ argc, argv };
    
    ExampleWidget wgt{};
    wgt.resize(250, 130);
    wgt.show();
    
    local_mousePress(&wgt, 125, 65);
    
    return app.exec();
}
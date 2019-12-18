#include "ExampleWidget.hpp"

#include <QMouseEvent>
#include <QDebug>


ExampleWidget::ExampleWidget(QWidget * pParWgt /* = nullptr */)
    : QLabel{ pParWgt } {}
    
void ExampleWidget::mousePressEvent(QMouseEvent *pEvent) {
        qDebug() << "a mouse button was pressed";
}    
    
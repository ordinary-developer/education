#include "ExampleWidget.hpp"

ExampleWidget::ExampleWidget(QWidget* parWgt /* = nullptr */)
    : QLabel(parWgt) {}
    
void ExampleWidget::enterEvent(QEvent* pEvent) {
    qDebug() << "enter event";
}    

void ExampleWidget::leaveEvent(QEvent* pEvent) {
    qDebug() << "leave event";
}
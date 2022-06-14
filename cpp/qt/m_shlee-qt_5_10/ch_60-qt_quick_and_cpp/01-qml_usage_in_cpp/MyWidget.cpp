#include <QtWidgets>
#include <QQuickWidget>
#include <QQuickItem>
#include "MyWidget.h"


MyWidget::MyWidget(QWidget * pWgt /* = 0 */) : QWidget(pWgt)
{
	QQuickWidget * pv = new QQuickWidget(QUrl("qrc:/main.qml"));
	QVBoxLayout * pVbox = new QVBoxLayout;
	pVbox->addWidget(pv);
	setLayout(pVbox);
}
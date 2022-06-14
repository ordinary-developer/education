#include <QtWidgets>
#include <QQuickWidget>
#include <QQuickItem>
#include <QDebug>
#include "MyWidget.h"


MyWidget::MyWidget(QWidget * pWgt /* = 0 */) : QWidget(pWgt)
{
	QQuickWidget * pv = new QQuickWidget(QUrl("qrc:/main.qml"));
	QVBoxLayout * pVbox = new QVBoxLayout;
	pVbox->addWidget(pv);
	setLayout(pVbox);
	
	QQuickItem * pqiRoot = pv->rootObject();
	if (pqiRoot) {
		pqiRoot->setProperty("color", "yellow");
		
		QObject * pObjText = pqiRoot->findChild<QObject*>("text");
		if (pObjText) {
			pObjText->setProperty("text", "C++");
			pObjText->setProperty("color", "blue");
			
			QVariant varRet;
			QMetaObject::invokeMethod(pObjText,
									  "setFontSize",
									  Q_RETURN_ARG(QVariant, varRet),
									  Q_ARG(QVariant, 52));
									  
			qDebug() << varRet;
		}
	}	
}
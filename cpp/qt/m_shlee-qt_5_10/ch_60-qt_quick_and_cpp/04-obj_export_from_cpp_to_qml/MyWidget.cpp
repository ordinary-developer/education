#include <QtWidgets>
#include <QQuickWidget>
#include <QQmlContext>

#include "MyWidget.h"

MyWidget::MyWidget(QWidget * pWgt /* = nullptr */) : QWidget{pWgt}
{
	QQuickWidget * pv = new QQuickWidget{QUrl{"qrc:/main.qml"}};
	
	QVBoxLayout * pvbx = new QVBoxLayout;
	pvbx->addWidget(pv);
	setLayout(pvbx);
	
	QQmlContext * pContext = pv->rootContext();
	QStringList lst{};
	for (int i = 0; i < 100; ++i) {
		lst << "Item" + QString::number(i);
	}
	QStringListModel * pmodel = new QStringListModel(this);
	pmodel->setStringList(lst);
	
	pContext->setContextProperty("myModel", pmodel);
	pContext->setContextProperty("myText", "It's my text!");
	pContext->setContextProperty("myColor", QColor(Qt::yellow));
	pContext->setContextProperty("myWidget", this);
}

void MyWidget::slotDisplayDialog()
{
	QMessageBox::information(0, "Message", "It's my message");
}

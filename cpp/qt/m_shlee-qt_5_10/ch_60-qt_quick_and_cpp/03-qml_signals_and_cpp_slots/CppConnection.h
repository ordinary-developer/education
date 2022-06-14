#pragma once
#include <QtCore>

class CppConnection : public QObject {
Q_OBJECT
public:
	CppConnection(QObject * pObj = 0)
		: QObject(pObj)
	{
	}
	
public slots:
	void slotQuit()
	{
		qApp->quit();
	}
	
	void slotInfo(const QString & str)
	{
		qDebug() << str;
	}
};

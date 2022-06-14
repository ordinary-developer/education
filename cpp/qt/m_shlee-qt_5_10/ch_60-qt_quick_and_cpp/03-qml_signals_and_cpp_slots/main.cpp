#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include "CppConnection.h"

int main(int argc, char ** argv) {
	QGuiApplication app(argc, argv);
	
	QQmlApplicationEngine eng;
	QQmlComponent comp(&eng, QUrl("qrc:/main.qml"));
	CppConnection cc;
	
	QObject * pObj = comp.create();
	
	QObject * pCmdQuitButton = pObj->findChild<QObject*>("QuitButton");
	if (pCmdQuitButton) {
		QObject::connect(pCmdQuitButton, SIGNAL(quitClicked()),
						 &cc, SLOT(slotQuit()));
	}
	
	QObject * pCmdInfoButton = pObj->findChild<QObject*>("InfoButton");
	if (pCmdInfoButton) {
		QObject::connect(pCmdInfoButton, SIGNAL(infoClicked(QString)),
						 &cc, SLOT(slotInfo(QString)));
	}
	
	return app.exec();
}
